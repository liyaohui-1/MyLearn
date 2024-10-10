#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
// bool ready = false;
int cargo = 0;

// void do_print_id(const int& id)
// {
//     std::unique_lock<std::mutex> lck(mtx);
//     while(!ready)
//         cv.wait(lck);
//     std::cout << "thread id: " << id << std::endl;
// }

// void go()
// {
//     ready = true;
//     cv.notify_all();
// }


void consumer()
{
    std::unique_lock < std::mutex > lck(mtx);
    cv.wait(lck,[](){return cargo != 0;});
    std::cout << "cargo: " << cargo << std::endl;
    cargo = 0;
}
void producer(int id)
{
    std::unique_lock < std::mutex > lck(mtx);
    cargo = id;
    // cv.notify_all();
    // 当调用该线程的函数退出时，所有在cond上等待的线程都会收到通知，与上面notify_all()类似
    std::notify_all_at_thread_exit(cv,std::move(lck));
}

int main(int argc,char* argv[])
{
    // std::thread threads[10];

    // for(int id = 0; id < 10; id++)
    // {
    //     threads[id] = std::thread(do_print_id,id);
    // }
    // std::cout << "10 threads ready to race..." << std::endl;
    // go();

    // for(auto &th:threads)
    //     th.join();

    std::thread consumers[10], producers[10];
    // spawn 10 consumers and 10 producers:
    for (int i = 0; i < 10; ++i) {
        consumers[i] = std::thread(consumer);
        producers[i] = std::thread(producer, i + 1);
    }
    // join them back:
    for (int i = 0; i < 10; ++i) {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}