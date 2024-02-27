#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class threadpool
{
public:
    static const int maxThreadPoolSize = 3;
public:
    threadpool();
    ~threadpool();
private:
    threadpool(const threadpool& p);
    threadpool& operator=(const threadpool& p);
public:
    enum taskPriorityE{level0, level1, level2};
    typedef std::function<void()> Task;
    typedef std::pair<taskPriorityE,Task> TaskPair;

    void start();
    void stop();
    void addTask(const Task&);
    void addTaskPair(const TaskPair&);

private:
    struct TaskPriorityCmp
    {
        bool operator()(const threadpool::TaskPair taskpair1,const threadpool::TaskPair taskpair2)
        {
            return taskpair1.first > taskpair2.first;//first的小值优先，小顶堆
        }
    };

    void threadloop();
    Task take();

    typedef std::vector<std::thread*> Threads;
    typedef std::priority_queue<TaskPair,std::vector<TaskPair>,TaskPriorityCmp> Tasks;

    Threads m_threads;
    Tasks m_task;
    std::mutex mtx;
    std::condition_variable cv;
    bool m_running;

};

#endif