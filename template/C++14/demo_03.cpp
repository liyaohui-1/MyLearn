#include <iostream>

// 函数模板，返回类型由 auto 推导
template<typename T, typename U>
auto add(T t, U u)
{
    return t + u;
}

int main()
{
    auto result = add(1, 2.5);                               // T 是 int，U 是 double
    std::cout << "Result of add: " << result << std::endl;   // 结果类型被推导为 double

    return 0;
}