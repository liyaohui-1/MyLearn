#include <iostream>
#include <type_traits>

// 函数重载，接受指针类型
void func(int* ptr)
{
    std::cout << "func(int* ptr) called" << std::endl;
}

// 函数重载，接受整型
void func(int value)
{
    std::cout << "func(int value) called" << std::endl;
}

// 模板函数，用于检查是否是 nullptr
template<typename T>
bool is_nullptr(T)
{
    return false;
}

// 模板特化，用于 nullptr
template<>
bool is_nullptr(std::nullptr_t)
{
    return true;
}

int main()
{
    int* p = nullptr;
    func(p);         // 调用 func(int* ptr)
    func(nullptr);   // 调用 func(int* ptr)，因为 nullptr 的类型是 std::nullptr_t

    int value = 0;
    func(value);   // 调用 func(int value)

    // 检查是否是 nullptr
    std::cout << std::boolalpha;
    std::cout << "is_nullptr(nullptr): " << is_nullptr(nullptr) << std::endl;
    std::cout << "is_nullptr(p): " << is_nullptr(p) << std::endl;
    std::cout << "is_nullptr(value): " << is_nullptr(value) << std::endl;

    return 0;
}