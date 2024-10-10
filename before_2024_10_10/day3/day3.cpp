#include <iostream>
#include <memory>
#include "text.h"

//argc：整数，为传给main的命令函参数个数
//argv[0]:为程序运行的全路径名
//argv[1]:为程序执行名后的第一个字符串
//argv[2]:为程序执行名后的第二个字符串 以此类推
int main(int argc,char* argv[])
{
    std::cout << "argc: " << argc << std::endl;
    std::cout << "exec.name: " << *argv[0] << std::endl;
    
    auto a = std::make_shared<A> ();

    std::cout << "a->GetA(): " <<a->GetA()  << std::endl; 
    std::cout << "a->GetB(): " <<a->GetB()  << std::endl; 
    std::cout << "A::GetB(): " <<A::GetB()  << std::endl;

    return 0;
}