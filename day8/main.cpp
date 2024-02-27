#include <iostream>
#include <vector>
#include <string>

constexpr int size()
{
    int a = 3;
    return a;
}

int foo()
{
    int x =1;
    return x;
}

int main()
{
    //1.long long 类型
    std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;

    //2.列表初始化、vector列表初始化
    int units_sold0 = 0;
    int units_sold1 = {0};
    int units_sold2{0};
    int units_sold3(0);

    std::vector<std::string> v1 = {"a", "an", "the"};
    // for(auto iter: v1)
    //     std::cout << iter << std::endl; 

    //3.nullptr
    int* p = nullptr;

    //4.constexpr变量
    constexpr int mf = 20; //20是常量表达式
    constexpr int limit = mf + 1;; //mf + 1是常量表达式
    constexpr int sz = size(); //只有当size是一个constexpr函数时才是一条正确语句

    //5.类型别名
    typedef std::vector<int> SI0; //传统定义类型别名的方法
    using SI = std::vector<int>; // C++11新标准定义类型别名的方法

    //6.auto类型说明符
    // auto i = 0,*p = &i; //正确,i是整数、p是整数指针
    // auto sz = 1,pi = 3.14; //错误：sz和pi的类型不一致

    int i =0,&r =i;
    auto a = r; //a是一个整数(r是i的别名，而i是一个整数)

    //auto一般会忽略掉顶层const
    const int ci = i,&cr = ci;
    auto b = ci;  //b是一个整数(顶层const被忽略掉)
    auto c = cr;  //c是一个整数(cr是ci的别名，ci本身是一个顶层const)
    auto d = &i;  //d是一个整形指针(对int类型取地址就是指向整形的指针)
    auto e = &ci; //e是一个指向整数常量的指针(对常量对象取地址是一种底层const)
    //如果希望推断出的auto类型是一个顶层const，需要明确指出
    const auto f = ci;  //ci推演类型是int，f是const int
    //注：符号&和*只从属于某个声明符，而非基本数据类型的一部分。


    //7.decltype类型指示符
    int x =100;
    decltype(foo()) sum =x;
    // std::cout << "sum: " << sum << std::endl;
    //decltype处理顶层const和引用的方式与auto有些许不同，如果decltype使用的表达式是一个变量，则decltype返回该变量的类型(包括const和引用在内)

    decltype(ci) x = 0;
    decltype(cr) y = x;
    // decltype(cr) z; //错误：z是一个引用，必须初始化
    

    return 0;
}