#include <iostream>

/*
    A类封装将构造函数和析构函数设置为protected：,这样做的原因有以下几点：
       （1）由于编译器在为类对象分配空间的时候，会检查类的析构函数的访问性，其实不光是析构函数，只要是非静态的函数，
           编译器都会检查。如果析构函数是私有的，那么编译器就不会在栈上为类对象分配空间。也就不能在栈上创建空间，只能在堆上创建对象。
       （2）如果A类作为基类，那么将A类的析构函数设置为private:是不合适的；因为如果A类要设置为基类，析构函数要设为virtual，
           子类就需要重写A类的析构函数。类外无法访问protected成员，子类可以访问父类protected成员。
*/

class A
{
    public:
        static A* create() 
        {
            std::cout << "In create..." << std::endl;
            return new A();
        }

        void destory() 
        {
            std::cout << "In destory..." << std::endl;
            delete this;
        }

    protected:  
        A() {}
        ~A() {}
};

/*
    B类将operator new和operator delete操作符封装为private，B类就不能使用new和delete操作符，
    也就不能在堆上创建对象，只能在栈上创建对象。
*/

class B
{
    public:
        B() {}
        ~B() {}
    private:
        void* operator new(size_t t) {} 
        void  operator delete(void* ptr) {}
};

int main()
{
    A* tmp = A::create();
    if(tmp)
    {
        tmp->destory();
    }

    return 0;
}