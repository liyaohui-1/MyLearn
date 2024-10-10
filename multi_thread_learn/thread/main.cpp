#include <thread>
#include <iostream>

void foo()
{
    std::cout << "thread id:" << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    std::thread t4(foo);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}