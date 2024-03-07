#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <list>
#include <map>
#include <algorithm>
#include <utility>

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

void error_msg(std::initializer_list<std::string> il)
{
    for(auto beg = il.begin(); beg != il.end(); beg++)
        std::cout << *beg << " ";

    std::cout << std::endl;
}

int main()
{
    //1.long long 类型
    // std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;

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

    decltype(ci) x1 = 0;
    decltype(cr) y = x1;
    // decltype(cr) z; //错误：z是一个引用，必须初始化

    //14.标准库函数begin和end
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int *beg = std::begin(arr);
    int *last = std::end(arr);
    while(beg != last && *beg >=0){
        ++(*beg++);
    }
    // for(auto it : arr)
    // {
    //     std::cout << it << std::endl;
    // }

    //15.使用auto和decltype简化声明
    int ia [3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for(auto p =std::begin(ia);p != std::end(ia); p++)
    {
        for(auto q = std::begin(*p);q != std::end(*p); q++)
        {
            // std::cout << *q << " ";
        }
        // std::cout<<std::endl;
    }

    //16.除法的舍入规则
    int a1 = 100;
    int a2 = 3;
    int a3 = -3;
    // std::cout << "a1/a2: " << a1/a2 <<",a1/a3: " << a1/a3 <<std::endl;
    // std::cout << "a1%a2: " << a1%a2 <<",a1%a3: " << a1%a3 <<std::endl;


    //17.用大括号包围的值列表赋
    int  k = 0;
    // k = {3.14}; //错误：窄化转换，丢失精度

    //20.标准库initializer_list类
    std::string expected = "expected";
    std::string actual = "actual";
    error_msg({expected,actual});

    std::vector<std::string> vv1 = {"a","an","the"};
    for(const auto &iter : vv1)
        std::cout << iter << " ";
    std::cout<<std::endl;
    std::list<std::string> vv2 = {"c","cat","car"};
    for(const auto &iter : vv2)
        std::cout << iter << " ";
    std::cout << std::endl;
    std::map<std::string,std::string> mmp = {{"123","456"},{"789","000"}};
    for(const auto &it : mmp)
        std::cout << "key: " << it.first << ",value:" << it.second << " ";
    std::cout << std::endl;

    std::map<std::string,int> mlp;
    std::vector<std::string> index = {"li","wang","zhao","sun","li"};
    for(auto iter : index)
    {
        if(mlp.count(iter) > 0)
            mlp[iter]++;
        else
            mlp.insert(std::make_pair(iter,1));
    }
    for(const auto &it : mlp)
        std::cout << "key: " << it.first << ",value:" << it.second << std::endl;

    //23.使用decltype简化返回类型定义
    int odd[] = {1,3,5,7,9};
    int even[] = {0,2,4,6,8};
    //有一个地方需要注意：decltype并不负责把数组类型转换成对应的指针，所以decltype的结果还是一个数组，
    //想要表示返回指针还必须在函数声明时加一个*符号。
    auto Func1 = [&odd,&even](int i) -> decltype(odd)* {return (i % 2) ? &odd : & even;};
    auto ret = Func1(5);
    for(auto it : *ret)
        std::cout << it <<" ";
    std::cout << std::endl;

    //33.容器的非成员函数swap
    std::vector<int> swap1 ={1,2,3,4,5,6,7,8,9,0};
    std::vector<int> swap2 ={6,7,8,9,0};
    std::cout << "before swap" << std::endl;
    for(auto swp1 : swap1)
        std::cout << swp1 << " ";
    std::cout << std::endl;

    for(auto swp2 : swap2)
        std::cout << swp2 << " ";
    std::cout << std::endl;
    swap(swap1,swap2);
    std::cout << "after swap" << std::endl;
    for(auto swp1 : swap1)
        std::cout << swp1 << " ";
    std::cout << std::endl;

    for(auto swp2 : swap2)
        std::cout << swp2 << " ";
    std::cout << std::endl;

    //39.lambda表达式中的尾置返回类型
    std::vector<int> tranVector;
    tranVector.push_back(10);
    tranVector.push_back(-20);
    for(auto it : tranVector)
        std::cout << it << " ";
    std::cout << std::endl;
    std::transform(tranVector.begin(),tranVector.end(),tranVector.begin(),[](int i ) -> int{return i < 0 ? -i : i;});
    for(auto it : tranVector)
        std::cout << it << " ";
    std::cout << std::endl;

    //51.范围for语句不能用于动态分配数组
    int *pp = new int[42];
    for(int i = 0; i <42;i++)
        pp[i] = i;
    for(int i = 0; i < 42; i++)
        std::cout <<"pp["<<i <<"]:" <<i << " ";
    std::cout << std::endl;
    if(pp){
        delete [] pp;
        pp = nullptr;
    }
    //54.allocator
    std::allocator<std::string> alloc;   //可以分配string的allocator对象
    auto const ap = alloc.allocate(3);    //分配3个未初始化的string,这个allocate调用为n个string分配了内存
    auto aq = ap;   //q指向最后构造的元素之后的位置
    alloc.construct(aq++);   //*q为空指针
    alloc.construct(aq++,10,'c');   //*q为cccccccccc
    alloc.construct(aq++,"hi");     //*q为hi

    //注意：还未构造对象的情况下就使用原始内存是错误的
    //当我们使用完对象后，必须对每个构造的元素调用destroy来销毁它们。函数destroy接受一个指针，对指向的对象执行析构函数
    while(*aq != *ap)
        alloc.destroy(--aq);//释放我们真正构造的string

    //释放内存通过deallocate来完成
    alloc.deallocate(ap,3);

    //59.move
    int&& rr1 = 42;
    int&& rr2 = std::move(rr1);

    rr1++;

    return 0;
}