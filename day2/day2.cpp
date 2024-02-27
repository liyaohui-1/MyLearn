#include <thread>
#include <iostream>
#include <chrono>

void task1()
{
    std::cout << "abc!" << std::endl;
}

void task2()
{
    std::cout << "def!" << std::endl;
}

void task3()
{
    std::cout << "ghi!" << std::endl;
}

int main()
{
    auto thread1 = std::thread(task1);
    auto thread2 = std::thread(task2);
    auto thread3 = std::thread(task3);
    //线程执行是没有顺序的

    thread1.join();
    thread2.join();
    thread3.join();
    
    return 0;
}