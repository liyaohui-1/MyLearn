#include <iostream>

template<int N>
constexpr int factorial()
{
    if constexpr (N > 1) {
        return N * factorial<N - 1>();   // 递归调用
    }
    else {
        return 1;   // 递归终止条件
    }
}

int main()
{
    constexpr int result = factorial<5>();         // 在编译时计算 5!
    std::cout << "5! = " << result << std::endl;   // 输出 "5! = 120"

    return 0;
}