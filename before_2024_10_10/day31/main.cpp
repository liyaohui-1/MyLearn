#include <iostream>                // std::cout
#include <future>                // std::async, std::future, std::launch
#include <chrono>                // std::chrono::milliseconds
#include <thread>                // std::this_thread::sleep_for

void do_print_ten(char c, int ms)
{
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::cout << c;
    }
}

int main(){
    std::cout << "with launch::async:\n";
    std::future < void >foo =
        std::async(std::launch::async, do_print_ten, '*', 100);
    std::future < void >bar =
        std::async(std::launch::async, do_print_ten, '@', 200);
    // async "get" (wait for foo and bar to be ready):
    foo.get();
    bar.get();
    std::cout << "\n\n";

    std::cout << "with launch::deferred:\n";
    foo = std::async(std::launch::deferred, do_print_ten, '*', 100);
    bar = std::async(std::launch::deferred, do_print_ten, '@', 200);
    // deferred "get" (perform the actual calls):
    foo.get();
    bar.get();
    std::cout << '\n';


    std::packaged_task<int(int)> fxx([](int x) { return x*2;}); // 默认构造函数

    std::future<int> ret = fxx.get_future();

    std::thread t(std::move(fxx), 10);  

    std::cout << "Result: " << ret.get() << std::endl;  

    if(t.joinable())
    {
        t.join();
    }

    return 0;
}

// #include <iostream>       // std::cout
// #include <future>         // std::async, std::future, std::shared_future

// int do_get_value() { return 10; }

// int main ()
// {
//     std::future<int> fut = std::async(do_get_value);
//     std::shared_future<int> shared_fut = fut.share();

//     // 共享的 future 对象可以被多次访问.
//     std::cout << "value: " << shared_fut.get() << '\n';
//     std::cout << "its double: " << shared_fut.get()*2 << '\n';

//     return 0;
// }

// // future example
// #include <iostream>             // std::cout
// #include <future>               // std::async, std::future
// #include <chrono>               // std::chrono::milliseconds

// // a non-optimized way of checking for prime numbers:
// bool
// is_prime(int x)
// {
//     for (int i = 2; i < x; ++i)
//         if (x % i == 0)
//             return false;
//     return true;
// }

// int main()
// {
//     // call function asynchronously:
//     std::future < bool > fut = std::async(is_prime, 444444443);

//     // do something while waiting for function to set future:
//     std::cout << "checking, please wait";
//     std::chrono::milliseconds span(100);
//     while (fut.wait_for(span) == std::future_status::timeout)
//         std::cout << '.';

//     bool x = fut.get();         // retrieve return value

//     std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";

//     return 0;
// }

// #include <iostream>     // std::cout
// #include <utility>      // std::move
// #include <future>       // std::packaged_task, std::future
// #include <thread>       // std::thread

// int main ()
// {
//     std::packaged_task<int(int)> foo; // 默认构造函数.

//     // 使用 lambda 表达式初始化一个 packaged_task 对象.
//     std::packaged_task<int(int)> bar([](int x){return x*2;});

//     foo = std::move(bar); // move-赋值操作，也是 C++11 中的新特性.

//     // 获取与 packaged_task 共享状态相关联的 future 对象.
//     std::future<int> ret = foo.get_future();

//     std::thread(std::move(foo), 10).detach(); // 产生线程，调用被包装的任务.

//     int value = ret.get(); // 等待任务完成并获取结果.
//     std::cout << "The double of 10 is " << value << ".\n";

//     return 0;
// }

// #include <iostream>     // std::cout
// #include <future>       // std::packaged_task, std::future
// #include <chrono>       // std::chrono::seconds
// #include <thread>       // std::thread, std::this_thread::sleep_for

// // count down taking a second for each value:
// int countdown (int from, int to) {
//     for (int i=from; i!=to; --i) {
//         std::cout << i << '\n';
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
//     std::cout << "Finished!\n";
//     return from - to;
// }

// int main ()
// {
//     std::packaged_task<int(int,int)> task(countdown); // 设置 packaged_task
//     std::future<int> ret = task.get_future(); // 获得与 packaged_task 共享状态相关联的 future 对象.

//     std::thread th(std::move(task), 10, 0);   //创建一个新线程完成计数任务.

//     int value = ret.get();                    // 等待任务完成并获取结果.

//     std::cout << "The countdown lasted for " << value << " seconds.\n";

//     th.join();
//     return 0;
// }

// #include <iostream>       // std::cout
// #include <thread>         // std::thread
// #include <future>         // std::promise, std::future

// std::promise<int> prom;

// void print_global_promise () {
//     std::future<int> fut = prom.get_future();
//     int x = fut.get();
//     std::cout << "value: " << x << '\n';
// }

// int main ()
// {
//     std::thread th1(print_global_promise);
//     prom.set_value(10);
//     th1.join();

//     prom = std::promise<int>();    // prom 被move赋值为一个新的 promise 对象.

//     std::thread th2 (print_global_promise);
//     prom.set_value (20);
//     th2.join();

//   return 0;
// }


// #include <iostream>       // std::cout
// #include <functional>     // std::ref
// #include <thread>         // std::thread
// #include <future>         // std::promise, std::future

// void print_int(std::future<int>& fut) {
//     std::cout << "wait..." << std::endl;
//     int x = fut.get(); // 获取共享状态的值.
//     std::cout << "value: " << x << '\n'; // 打印 value: 10.
// }

// int main ()
// {
//     std::promise<int> prom; // 生成一个 std::promise<int> 对象.
//     std::future<int> fut = prom.get_future(); // 和 future 关联.
//     std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.
//     // prom.set_value(10); // 设置共享状态的值, 此处和线程t保持同步.
//     t.join();
//     return 0;
// }