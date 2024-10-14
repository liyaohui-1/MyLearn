#include <iostream>
#include <thread>
#include <mutex>
 
std::once_flag flag1;
 
void simple_do_once()
{
    std::call_once(flag1, [](){ std::cout << "Simple example: called once\n"; });
}
 
int main()
{
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
}

// #include <thread>
// #include <string>
// #include <iostream>

// class A
// {
//     public:
//         A() {}
//         ~A() {}
    
//     void test(const std::string& str)
//     {
//         thread_local int count = 0;
//         ++count;
//         std::cout << str << " " << count << std::endl;
//     }
// };

// void func(const std::string& str)
// {
//     A a1;
//     a1.test(str);
//     a1.test(str);

//     A a2;
//     a2.test(str);
//     a2.test(str);
// }

// int main()
// {
//     std::thread t1(func, "t1");
//     t1.join();
//     std::thread t2(func, "t2");
//     t2.join();

//     return 0;
// }