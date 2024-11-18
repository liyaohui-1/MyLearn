#include <iostream>
#include <list>
#include <vector>

// 通用的处理函数，接受任何容器和任何操作
template<typename Container, typename Func>
void process_elements(Container&& container, Func func)
{
    for (const auto& element : container) {
        func(element);   //把元素的操作权限，放到外面去
    }
}

int main()
{
    std::vector<double> vec = {1.1, 2.2, 3.3};
    std::list<int>      lst = {4, 5, 6};

    // 使用泛型 lambda 表达式处理不同类型的容器 【万能打印】
    auto print = [](const auto& value) { std::cout << value << ' '; };

    std::cout << "打印 Vector 元素: ";
    process_elements(vec, print);
    std::cout << "\n 打印 List 元素: ";
    process_elements(lst, print);
    std::cout << std::endl;

    return 0;
}