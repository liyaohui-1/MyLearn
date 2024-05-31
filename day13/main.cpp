#include <vector>
#include <string>
#include <iostream> 
#include <exception>

void foo1()
{
    try
    {
        std::vector<std::string> tmp;
        std::cout << tmp[2] << std::endl;
        std::cout << "tmp.size(): " << tmp.size() << std::endl;

    }catch(const std::exception& e)
    {
        std::cerr << "err: " << e.what() << std::endl;
    }
}

void foo2()
{
    try
    {
        std::vector<std::string> tmp;
        std::cout << tmp.at(2) << std::endl;
        std::cout << "tmp.size(): " << tmp.size() << std::endl;

    }catch(const std::exception& e)
    {
        std::cerr << "err: " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[])
{
    foo2();

    return 0;
}