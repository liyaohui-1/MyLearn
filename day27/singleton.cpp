#include <iostream>
using namespace std;

class Singleton
{
public:
    ~Singleton()
    {
        cout << "Destructor called!" << endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton &get_instance()
    {
        static Singleton instance;
        return instance;
    }
    void use() const { cout << "in use" << endl; }

private:
    Singleton()
    {
        cout << "Constructor Called!" << endl;
    }
};

int main(int argc,char* argv[])
{
    Singleton& instance_1 = Singleton::get_instance();
    Singleton& instance_2 = Singleton::get_instance();
    instance_1.use();
    return 0;
}