#include <iostream>
#include <functional>
#include <map>
#include <algorithm>

//普通函数
int commFunc(int lhs,int rhs)
{
    return lhs + rhs;
}

//lambda函数表达式
auto lamdaFunc = [] (int lhs,int rhs) -> int{return lhs + rhs;};

//函数对象
class Functor
{
    public:
        int operator()(int lhs,int rhs)
        {
            return lhs + rhs;
        }
};

//类成员函数
class Randy
{
    public:
        int randy_function(int lhs,int rhs){return lhs+rhs;}
        static int static_randy_function(int lhs,int rhs){return lhs+rhs;}

};

std::map<std::string,std::function<int(int,int)>> binOps = {
    {"+",[](int a, int b)->int{return a+b;}},
    {"-",[](int a, int b)->int{return a-b;}},
    {"*",[](int a, int b)->int{return a*b;}},
    {"/",[](int a, int b)->int{return a/b;}},
    {"%",[](int a, int b)->int{return a%b;}},
};


int main()
{
    std::function<int(int,int)> callback;
    int result = -1;

    //普通函数
    callback = commFunc;
    result = callback(1,2);
    std::cout << "commFunc result: " << result << std::endl;

    //函数指针
    callback = &commFunc;
    result = callback(1,2);
    std::cout << "commFunc pointer: " << result <<std::endl;

    //lambda表达式
    callback = lamdaFunc;
    result = lamdaFunc(1,2);
    std::cout << "lamdaFunc : " << result <<std::endl;

    //函数对象
    Functor functor_randy;
    callback = functor_randy;
    result = functor_randy(1,2);
    std::cout << "class function : " << result <<std::endl;

    //类成员函数(使用std::bind绑定类成员函数，std::placeholders::_1为占位符，顺序与原函数入参对应，顺序可调换)
    //callback = std::bind(&Randy::randy_function,randy,std::placeholders::_2,std::placeholders::_1);
    //上式也可以这么写，调用时，第2个参数在前，第1个参数在后

    // auto newcallback = std::bind(calllback, arg_list);
    //调用newcallback时，实际调用的是callback,并传给它arg_list的参数.
    Randy randy;
    callback = std::bind(&Randy::randy_function,randy,std::placeholders::_1,std::placeholders::_2);
    result = callback(1,2);
    std::cout << "class member function : " << result <<std::endl;

    //类静态成员
    callback = Randy::static_randy_function;
    result = callback(1,2);
    std::cout << "static class member function : " << result <<std::endl;

    int left,right;
    std::string op;
    while(true)
    {
        std::cin>>left>>op>>right;
        std::cout <<left << op << right << "="<< binOps[op](left,right) << std::endl;
    }
    

    return 0;
}
