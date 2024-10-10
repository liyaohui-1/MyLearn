#ifndef WEIGHT_H_
#define WEIGHT_H_

#include <memory>

class weight
{
    public:
        weight();
        ~weight();
        weight(const weight& other);
        weight& operator=(const weight& rhs);
    
    private:
        struct IPMPIL;
        std::unique_ptr<IPMPIL> ipmpil;
};


#endif