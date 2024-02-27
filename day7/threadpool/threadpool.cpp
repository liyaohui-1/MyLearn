#include "threadpool.h"
#include <assert.h>
#include <unistd.h>
#include <iostream>

threadpool::threadpool():m_running(false)
{

}

threadpool::~threadpool()
{
    if(m_running)
    {
        stop();
    }
}

void threadpool::start()
{
    m_running = true;
    m_threads.reserve(maxThreadPoolSize);
    for(int i = 0; i < maxThreadPoolSize; i++)
    {
        m_threads.push_back(new std::thread(std::bind(&threadpool::threadloop,this)));
    }
}

void threadpool::stop()
{
    std::cout << "thread stop.." << std::endl;
    {
        std::unique_lock<std::mutex> lk(mtx);
        m_running = false;
        cv.notify_all();
        std::cout << "thread notify_all.." << std::endl;
    }

    for(auto iter:m_threads)
    {
        if(iter->joinable())
        {
            iter->join();
            delete iter;
        }
    }
    m_threads.clear();
}

void threadpool::threadloop()
{
    std::cout << "thread_id: " << std::this_thread::get_id() << " start.."<<std::endl;
    while(m_running)
    {
        Task task = take();
        if(task)
            task();
    }
    std::cout << "thread_id: " << std::this_thread::get_id() <<" exit.." <<std::endl;
}

void threadpool::addTask(const Task& task)
{
    std::unique_lock<std::mutex> lk(mtx);
    TaskPair taskpair(level2,task);
    m_task.push(taskpair);
    cv.notify_all();
}

void threadpool::addTaskPair(const TaskPair& task)
{
    std::unique_lock<std::mutex> lk(mtx);
    m_task.push(task);
    cv.notify_all();
}

threadpool::Task threadpool::take()
{
    std::unique_lock<std::mutex> lk(mtx);
    while(m_task.empty() && m_running)
    {
        std::cout << "thread_id: " << std::this_thread::get_id() << " wait.."<<std::endl;
        cv.wait(lk);
    }
    std::cout << "thread_id: " << std::this_thread::get_id() << " weakup.."<<std::endl;

    Task task;
    Tasks::size_type size = m_task.size();
    if(!m_task.empty() && m_running)
    {
        task = m_task.top().second;
        m_task.pop();
        assert(size - 1 == m_task.size());
    }
    return task;
}