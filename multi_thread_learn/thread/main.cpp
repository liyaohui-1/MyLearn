#include <iostream>
#include <atomic>
#include <thread>

namespace
{
std::atomic<int> a;
}

void fun()
{
    for (int i = 0; i < 100; ++i) {
        a.fetch_add(1);
    }
}

int main()
{
    std::thread t1(fun);
    std::thread t2(fun);
    t1.join();
    t2.join();
    std::cout << "value of a: " << a << std::endl;

    return 0;
}