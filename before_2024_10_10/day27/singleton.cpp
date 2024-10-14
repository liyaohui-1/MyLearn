#include <iostream>
using namespace std;

class Singleton
{
public:
    ~Singleton()
    {
        cout << "Destructor called!" << endl;
    }

    static Singleton &get_instance()
    {
        static Singleton instance(100);
        return instance;
    }
    void use() const
    {
        cout << "in use" << endl;
    }
    uint8_t get_value() const
    {
        cout << "tmp: " << (int)tmp << endl;
        return tmp;
    }

private:
    Singleton(uint8_t tt) : tmp(tt)
    {
        cout << "Constructor Called!" << endl;
    }
    //拷贝构造函数
    Singleton(const Singleton &other)
    {
        tmp = other.get_value();
    }
    //运算符重载函数
    Singleton &operator=(const Singleton &other)
    {
        if (this != &other)
        {
            tmp = other.get_value();
        }
        return *this;
    }

private:
    uint8_t tmp = 0;
};

int main(int argc, char *argv[])
{
    Singleton &instance_1 = Singleton::get_instance();
    Singleton &instance_2 = Singleton::get_instance();
    instance_1.use();
    instance_1.get_value();
    return 0;
}