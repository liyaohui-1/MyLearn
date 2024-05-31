#include <weight.h>

#include <string>
#include <vector>
#include <iostream>
#include "gadget.h"

struct weight::IPMPIL
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

weight::weight() : ipmpil(std::make_unique<IPMPIL> ())
{
    std::cout << "In constructor!" << std::endl;
}

weight::~weight()
{
    std::cout << "In destructor!" <<std::endl;
}

weight::weight(const weight& other) : ipmpil(std::make_unique<IPMPIL> (*other.ipmpil))
{
    std::cout << "In copy constuctor!" << std::endl;
}

weight& weight::operator=(const weight& rhs)
{
    std::cout << "In operator = !" << std::endl;
    *ipmpil = *rhs.ipmpil;
    return *this;
}