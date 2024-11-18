#include <iomanip>
#include <iostream>

// 变量模板定义
template<typename T>
constexpr T pi = T(3.1415926535897932385);

int main()
{
    // 使用变量模板实例化不同类型的pi
    std::cout << "pi<float>: " << pi<float> << std::setprecision(20) << std::endl;
    std::cout << "pi<double>: " << pi<double> << std::setprecision(20) << std::endl;
    std::cout << "pi<long double>: " << pi<long double> << std::setprecision(20) << std::endl;

    return 0;
}