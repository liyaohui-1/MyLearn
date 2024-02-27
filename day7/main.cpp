#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "threadpool.h"

std::mutex g_mtx;

void priorityFunc()
{
    for(int i = 1; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lk(g_mtx);
        std::cout << "priorityFunc[" << i <<"] on pid" << std::this_thread::get_id() << std::endl; 
    }
}

void testFunc()
{
    for(int i = 1; i < 4; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lk(g_mtx);
        std::cout << "testFunc[" << i <<"] on pid" << std::this_thread::get_id() << std::endl; 
    }
}


int main()
{
    threadpool tp;
    tp.start();

    for(int i = 0; i < 5; i++)
        tp.addTask(testFunc);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    tp.addTaskPair(threadpool::TaskPair(threadpool::level0,priorityFunc));

    getchar();//主线程阻塞，等待线程池中的任务全部执行完成

    return 0;
}