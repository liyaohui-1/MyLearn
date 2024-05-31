#include <weight.h>
#include <iostream>

int main(int argc,char* argv[])
{
    weight tmp;

    std::cout << "weight *************" << std::endl;

    weight tmp1(tmp);

    std::cout << "weight1 ************" << std::endl;

    weight tmp2;
    tmp2 = tmp;

    std::cout << "weight2 ************" << std::endl;


    return 0;
}