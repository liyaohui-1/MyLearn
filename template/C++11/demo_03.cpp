#include <functional>
#include <iostream>

// 定义一个函数指针的模板别名
template<typename ReturnType, typename... Args>
using FuncPtr = ReturnType (*)(Args...);

// 定义一个函数对象的模板别名
template<typename ReturnType, typename... Args>
using FuncObj = std::function<ReturnType(Args...)>;

// 一个简单的函数
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // 使用模板别名创建函数指针
    FuncPtr<int, int, int> ptr = add;
    std::cout << "Function pointer result: " << ptr(2, 3) << std::endl;

    // 使用模板别名创建函数对象
    FuncObj<int, int, int> obj = add;
    std::cout << "Function object result: " << obj(3, 4) << std::endl;

    return 0;
}