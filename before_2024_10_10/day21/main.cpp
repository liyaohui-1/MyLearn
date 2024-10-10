#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

/*accumulate函数仿写*/
// version1-普通操作版本
template<class InputIterator,class T>
T accumulate_l(InputIterator first,InputIterator last,T init)
{
    for(;first != last; ++first)
        init = init + *first;
    return init;
}

// version2-泛化操作版本
template<class InputIterator,class T,class BinaryOperation>
T accumulate_l(InputIterator first,InputIterator last,T init,BinaryOperation binary_op)
{
    for(;first != last; ++first)
        init = binary_op(init,*first);
    return init;
}


/*partial_sum函数仿写，求局部累加和*/
//version2-泛化操作版本
template <class InputIterator, class OutputIterator, class T, class BinaryOperation>  
OutputIterator __partial_sum(InputIterator first, InputIterator last,  
                             OutputIterator result,  
                             BinaryOperation binary_op) 
{  
    T value = *first;  
    *result = value;  
    while (++first != last) {  
        value = binary_op(value, *first);  
        *++result = value;  
    }  
    return result;  
}  
  
template <class InputIterator, class OutputIterator, class BinaryOperation>  
OutputIterator partial_sum_l(InputIterator first, InputIterator last,  
                           OutputIterator result,  
                           BinaryOperation binary_op) 
{  
    if (first == last) return result;  
  
    // 使用 std::iterator_traits 来获取迭代器所指向的元素的类型  
    using ValueType = typename std::iterator_traits<InputIterator>::value_type;  
  
    return __partial_sum<InputIterator, OutputIterator, ValueType>(first, last, result, binary_op);  
}

bool isSpace(char x) { return x == ' ';}


struct Calculate 
{  
    Calculate(int& i) 
    {  
        i = i * 100;   
    }  
    int value;   
};  
  
struct Gadget 
{  
    Gadget(const Calculate& clc_param) : clc(clc_param) {}   
    Calculate clc;  
};  
  
void fun(int& i) 
{  
    Gadget g{Calculate(i)}; //C++11之后可以使用花括号进行类的初始化操作
}

int main()
{
    int A[] = {1,2,3,4,5};
    const int N = sizeof(A)/sizeof(A[0]);

    std::cout << "The sum of all elements in A is "
         << accumulate_l(A, A+N, 0)
         << endl;

    std::cout << "The product of all elements in A is "
         << accumulate_l(A, A+N, 1, [](int argv1,int argv2)->int{return argv1*argv2;})
         << endl;

    vector<int> vec = {1, 2, 3, 4, 5};  
    vector<int> result(vec.size());  
  
    // 使用 partial_sum_l 计算前缀和  
    auto it = partial_sum_l(vec.begin(), vec.end(), result.begin(), std::plus<int>());  
  
    // 输出结果  
    for (int n : result) {  
        std::cout << n << ' ';  
    }  
    std::cout << '\n';


    srand(unsigned(time(0)));
	int count = rand() % 3 + 1;    //范围1~3
	int count1 = rand() % 3;    //范围0~2
	cout << count << endl << count1 << endl;

    // 随机数种子
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);	 // 大随机数
	cout << rand_num() << endl;

    // 给定范围
    uniform_int_distribution<long long> dist(0, 1000000);  // 给定范围
	cout << dist(rand_num) << endl;


    string s2("Text with    spaces");
	cout << "删除之前"<<s2 << endl;
	s2.erase(remove_if(s2.begin(), s2.end(), isSpace), s2.end());
	cout <<"删除之后"<< s2 << endl;

    int i = 3;
    fun(i);
    std::cout << i << endl;

    return 0;
}