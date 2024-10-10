#include <iostream>
#include <memory>
#include "template.h"
// #include "base.h"

using a::b::c::GrandFather;
using a::b::c::Father;
using a::b::c::Son;

int main()
{
    Son<int> *ptr = new Son<int> ();
    std::cout << "before ptr->SonGetGrandFatherValue():" << ptr->SonGetGrandFatherValue() << std::endl; 
    ptr->SonSetGrandFatherValue(100);
    std::cout << "after ptr->SonGetGrandFatherValue():" << ptr->SonGetGrandFatherValue() << std::endl; 

    std::cout << "Hello world!" << std::endl;
    delete ptr;
    return 0;
}