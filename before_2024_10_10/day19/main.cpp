#include <iostream>
#include <memory>

class unreferenceable
{
    public:
        unreferenceable* operator &() {return nullptr;}
        int x;
};

void print(unreferenceable* m)
{
    if(m)
    {
        std::cout << "m->x: " << m->x << std::endl;
    }
    else
    {
        std::cout << "[null pointer]" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    void (*pfn)(unreferenceable*) = std::addressof(print);

    unreferenceable val {10};
    unreferenceable* foo = &val;
    unreferenceable* bar = std::addressof(val);

    pfn(foo);
    pfn(bar);

    return 0;
}

//addressof(T& ref)函数，返回ref引用的对象或函数的地址。