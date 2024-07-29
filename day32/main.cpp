#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock, std::unique_lock
                          // std::adopt_lock, std::defer_lock
std::mutex foo,bar;

void task_a () {
  std::lock (foo,bar);         // simultaneous lock (prevents deadlock)
  std::unique_lock<std::mutex> lck1 (foo,std::adopt_lock);
  std::unique_lock<std::mutex> lck2 (bar,std::adopt_lock);
  std::cout << "task a\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}

void task_b () {
  // foo.lock(); bar.lock(); // replaced by:
  std::unique_lock<std::mutex> lck1, lck2;
  lck1 = std::unique_lock<std::mutex>(bar,std::defer_lock);
  lck2 = std::unique_lock<std::mutex>(foo,std::defer_lock);
  std::lock (lck1,lck2);       // simultaneous lock (prevents deadlock)
  std::cout << "task b\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}


int main ()
{
  std::thread th1 (task_a);
  std::thread th2 (task_b);

  th1.join();
  th2.join();

  return 0;
}

// #include <iostream>       // std::cout
// #include <thread>         // std::thread
// #include <mutex>          // std::mutex, std::lock_guard
// #include <stdexcept>      // std::logic_error

// std::mutex mtx;

// void print_even (int x) {
//     if (x%2==0) 
//         std::cout << x << " is even\n";
//     else 
//         throw (std::logic_error("not even"));
// }

// void print_thread_id (int id) {
//     try {
//         // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
//         std::lock_guard<std::mutex> lck (mtx);
//         print_even(id);
//     }
//     catch (std::logic_error&) {
//         std::cout << "[exception caught]\n";
//     }
// }

// int main ()
// {
//     std::thread threads[10];
//     // spawn 10 threads:
//     for (int i=0; i<10; ++i)
//         threads[i] = std::thread(print_thread_id,i+1);

//     for (auto& th : threads) th.join();

//     return 0;
// }

// #include <iostream>       // std::cout
// #include <thread>         // std::thread
// #include <mutex>          // std::mutex

// volatile int counter = 0; // non-atomic counter
// std::mutex mtx;           // locks access to counter

// void attempt_10k_increases() {
//     for (int i=0; i<10000; ++i) {
//         if (mtx.try_lock()) {   // only increase if currently not locked:
//             ++counter;
//             mtx.unlock();
//         }
//     }
// }

// int main (int argc, const char* argv[]) {

//     if(argc < 2)
//         return 0;

//     for(int i = 0; i < argc; i++)
//         std::cout << "argv[" << i <<"]:" << argv[i] << ",";
//     std::cout << std::endl;

//     int thread_num = atoi(argv[1]);
//     std::thread threads[thread_num];
//     for (int i = 0; i < thread_num; ++i)
//         threads[i] = std::thread(attempt_10k_increases);

//     for (auto& th : threads) 
//         th.join();
//     std::cout << counter << " successful increases of the counter.\n";

//     return 0;
// }