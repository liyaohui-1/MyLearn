#include <iostream>
#include <vector>

template<typename T>
int compare(const T &v1,const T &v2)
{
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
       return 1;
    
    return 0;
}

class A
{
    public:
        void foo ()
        {
            std::cout << "A::foo()" << std::endl;
        }
};

class B : public A
{
    public:
        void foo ()
        {
            std::cout << "B::foo()" << std::endl;
        }
};

int main()
{
    //编译器用推断出的模板参数来为我们实例化一个特定版本的函数。
    //当编译器实例化一个模板时，它使用实际的模板实参代替对应的模板参数来创建出模板的一个新“实例”。
    // std::cout << "compare Result1: " << compare(1,2) << std::endl;
    std::vector<int> v1{1,2,3},v2{4,5,6};
    // std::cout << "compare Result2: " << compare(v1,v2) << std::endl;

    A a;
    B b;
    a.foo();
    b.foo();

    return 0;
}