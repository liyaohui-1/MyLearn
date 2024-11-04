/*
    std::enable_if使用场景
    1、限制模板函数的参数类型
    在某些场景下，我们需要实现只有特定类型可以调用的模板函数。
    如下代码所示，通过对返回值使用std::enable_if和在模板参数中使用std::enable_if均实现了只允许整形参数调用函数的功能。
*/

#if 0
// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T> 
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i) 
{ 
    return bool(i % 2); 
}

// 2. the second template argument is only valid if T is an integral type:
template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type> 
bool is_even(T i)
{
    return !bool(i % 2);
}

int main()
{
    short int i = 1; // code does not compile if type of i is not integral

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;

    return 0;
}
#else
/*
    2. 模板类型偏特化
    在使用模板编程时，可以利用std::enable_if的特性根据模板参数的不同特性进行不同的类型选择。
    如下所示，我们可以实现一个检测变量是否为智能指针的实现
*/
#include <iostream>
#include <type_traits>
#include <memory>
 
template <typename T>
struct is_smart_pointer_helper : public std::false_type {};
 
template <typename T>
struct is_smart_pointer_helper<std::shared_ptr<T> > : public std::true_type {};
 
template <typename T>
struct is_smart_pointer_helper<std::unique_ptr<T> > : public std::true_type {};
 
template <typename T>
struct is_smart_pointer_helper<std::weak_ptr<T> > : public std::true_type {};
 
template <typename T>
struct is_smart_pointer : public is_smart_pointer_helper<typename std::remove_cv<T>::type> {};
 
template <typename T>
typename std::enable_if<is_smart_pointer<T>::value,void>::type check_smart_pointer(const T& t)
{
    std::cout << "is smart pointer" << std::endl;
}

template <typename T>
typename std::enable_if<!is_smart_pointer<T>::value,void>::type check_smart_pointer(const T& t)
{
    std::cout << "not smart pointer" << std::endl;
}
 
int main()
{
    int* p(new int(2));
    std::shared_ptr<int> pp(new int(2));
    std::unique_ptr<int> upp(new int(4));

    check_smart_pointer(p);
    check_smart_pointer(pp);
    check_smart_pointer(upp);

    return 0;
}

#endif