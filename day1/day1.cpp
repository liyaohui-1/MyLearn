#include <iostream>
#include <string>
#include <map>

class A
{
    public:
        void foo(void)
        {
            std::cout << "A" << std::endl;
        }
};

class B : public A
{
    public:
        void foo(void)
        {
            std::cout << "B" << std::endl;
        }
};

int main(int argc,char* argv[])
{
    A *a = new B;
    a->foo();//A:此时调用的是父类的函数，父类对象的指针调用不到子类对象的函数

    B *b = new B;
    b->foo();//B:此时调用的是子类的函数，子类的同名函数隐藏了父类函数

    std::map<std::string,int> tmp;
    int x = tmp["abc"]; 
    //返回值：对等效于k的键值的映射值的引用
    //注意：将一个新的关键字"abc"插入tmp中，关键字是一个const string,保存abc。stl库中的值进行初始化，在本例这种意味着值为0。
    int z = tmp["abcd"]; 
    tmp["abc"] = 2;
    int y = tmp["abc"];
    std::cout << "x: " << x << std::endl; //0
    std::cout << "y: " << y << std::endl; //2
    std::cout << "z: " << z << std::endl; //0
    std::cout << "tmp.size(): " << tmp.size() << std::endl; //2

    return 0;
}