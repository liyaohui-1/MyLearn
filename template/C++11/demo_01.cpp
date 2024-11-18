#include <iostream>
#include <typeinfo>
#include <vector>

// 模板函数，使用 auto 推导参数类型
template<typename T>
void printElements(const std::vector<T>& vec)
{
    for (const auto& element : vec) { std::cout << element << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector<int>         intVec    = {1, 2, 3, 4, 5};
    std::vector<std::string> stringVec = {"one", "two", "three", "four", "five"};

    // 调用模板函数，编译器推导出 T 的类型
    printElements(intVec);      // T 推导为 int
    printElements(stringVec);   // T 推导为 std::string

    return 0;
}