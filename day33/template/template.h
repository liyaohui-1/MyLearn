#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <functional>

namespace a{
namespace b{
namespace c{

    class GrandFather
    {    
        public:
            GrandFather(): test(0)
                {};
            virtual ~GrandFather() {};
        protected:
            uint64_t test;
    };


    template <typename M>
    class Father :public GrandFather
    {
        public:
        using SubscribeCbk = std::function<bool(const M&)>;

        Father() : GrandFather() 
        {};
        virtual ~Father() {};

    };

    template <typename T>
    class Son : public Father<T>
    {
        public:
            Son() : Father<T> ()
                {}

        uint64_t SonGetGrandFatherValue() {return this->test;}
        void SonSetGrandFatherValue(uint64_t tmp ) { this->test = tmp;}

            
    };
}
}
}

#endif
