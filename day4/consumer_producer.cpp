#include <iostream>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <memory>
#include <chrono>

class PCmode
{
    public:
        PCmode():m_bRunning(true),data_size(1),data_index(0)
        {
        }

        ~PCmode()
        {
            m_bRunning = false;
        }

    public:
        void ProductThread(int n) //生产线程函数
        {
            data_index = n;
            while(m_bRunning)
            {
                // std::this_thread::sleep_for(std::chrono::milliseconds(1));

                std::unique_lock<std::mutex> lk(cvMtx);
                cv.wait(lk,[this]()->bool{return data_deq.size() < data_size;});

                data_deq.push_back(data_index);
                std::cout << "produce_data: " << data_index << ",queue.size():" << data_deq.size() << std::endl;

                cv.notify_all();
            }
        }

        void ConsumerThread() //消费线程函数
        {
            while(m_bRunning)
            {
                std::unique_lock<std::mutex> lk(cvMtx);
                cv.wait(lk,[this]()->bool{return !data_deq.empty();});

                int data = data_deq.front();
                data_deq.pop_front();
                std::cout << "consume_data: " << data << ",queue.size():" << data_deq.size() << std::endl;
                cv.notify_all();
            }
        }

    private:
        bool m_bRunning;

        std::mutex cvMtx;
        std::condition_variable cv;

        std::deque<int> data_deq;
        size_t data_size;
        int data_index;
};

int main()
{
    auto pcObj = std::make_shared<PCmode> ();
    int n =10;

    std::thread produceThread = std::thread(&PCmode::ProductThread,pcObj.get(),n);
    std::thread consumeThread = std::thread(&PCmode::ConsumerThread,pcObj.get());

    produceThread.join();
    consumeThread.join();

    return 0;
}