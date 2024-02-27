#include <string.h>
#include <iostream>
#include <string>

class A
{
    public:
        //1. 如果成员变量为引用类型，那么形参也应为引用类型
        //2. 引用必须在链表里面赋值，不能在函数体内赋值，如果在函数体内赋值，相当于修改引用的值，而引用不能修改
        A(int& b, int a = 100):m_a(a),m_b(b)
        {
            std::cout << "调用构造函数.." << std::endl;
            m_d = new char[1024];
        }

        ~A()
        {
            std::cout << "调用析构函数.." << std::endl;
            delete []m_d;
        }

        A(const A& other):m_b(other.m_b)
        {
            std::cout << "调用拷贝构造函数.." << std::endl;
            m_a = other.m_a;

            m_d = new char[1024];
            memcpy(m_d,other.m_d,1024);
        }

        void SetString(const char* str)
        {
            //const char*不能赋值给char*,所以需要这样赋值
            if(m_d)
                delete []m_d;
            m_d = new char[strlen(str)+1];
            std::cout << "strlent(str): " << strlen(str) << std::endl;
            memcpy(m_d,str,strlen(str)+1);
        }

        void ShowString()
        {
            std::cout << "str: " << m_d << std::endl;
        }

        void SetInt(const int& tmp)
        {
            m_a = tmp;
        }

        A& operator= (const A& other)
        {
            std::cout << "调用赋值运算符重载函数.." << std::endl;
            if(this != &other)
            {
                m_a = other.m_a;
                m_b = other.m_b;

                m_d = new char[strlen(other.m_d)+1];
                memcpy(m_d,other.m_d,1024);
           }
           return *this;
        }

        void operator +=(const A& other)
        {
            std::cout << "调用 += 重载函数.." << std::endl;
            if(this != &other)
            {
                m_a += other.m_a;
                m_b += other.m_b;

                strcat(m_d,other.m_d);
            }
        }

        bool operator == (const A& other)
        {
            if(this != &other)
            {
                return m_a == other.m_a && m_b == other.m_b && !strcmp(m_d,other.m_d);
            }
            return true;
        }

    private:
        int m_a;
        int& m_b;
        const static int m_c[5];
        char* m_d;
};
//static成员变量必须在类外进行声明，并开辟空间
const int A::m_c[5] = {0,1,2,3,4}; 

int main()
{
    int a1 = 20;
    A a(a1);
    a.SetString("123");
    a.ShowString();
    a.SetInt(1);
    
    std::cout << "ccccccccccccc" << std::endl;
    A b(a);

    int c1 = 10;
    A c(c1,1000);
    c.SetString("456");
    c.ShowString();

    std::cout << "a+c:a+c:a+c:a+c:a+c:" << std::endl;
    c += a;
    c.ShowString();

    if(a == c){
        std::cout << "a == c" << std::endl;
    }else{
        std::cout << "a != c" << std::endl;
    }

    if(a == b){
        std::cout << "a == b" << std::endl;
    }else{
        std::cout << "a != b" << std::endl;
    }

    //这个赋值为什么正确？
    //答：尽管xy是一个整形常量，但无论如何xy的值还是一个整数型。
    //   xy的常量特征仅仅在执行改变xy的操作时才会发生作用。当xy去初始化xz时，无需在意xy是不是一个常量。
    //   拷贝一个对象的值并不会改变它，一旦拷贝完成，新的对象和原来的对象就没什么关系了。见《C++ primer》53页。
    const int xy =1;
    int xz = xy;
    std::cout << "xy.address: " <<&xy <<",xz.address: " << &xz << std::endl;


    /*
    下面两个赋值均错误：
    const char* str11 = "123";
    char* str22 = str11;

    const int aa[5] = {1,2,3,4,5};
    int bb = aa;
    */

   const char* str11 = "123";
   const char* str22 = str11;
//    std::cout << "str11.address: " <<&str11 <<",str22.address: " << &str22 << std::endl;

   int aa[5] = {1,2,3,4,5};
   int bb[3] = {1,2,3};
   //第一种：这里是一个const指针，const修饰指针，cc指针本身不能改变，指向的内容能改变
   int* const cc = aa;
   
   cc[1] = 7;
   // cc = bb;  //报错
   
   //第二种：这里const修改int类型的值，dd指针本身能改变，指向的内容不能改变
   const int* dd = aa;
   // dd[3] = 8;//报错
   dd = bb; //正确

   //第三种:
   //这里限定指向和指向的值，ee指针本身和指向的内容都不能改变
   const int* const ee = aa;
   //ee[0] = 2; //报错
   //ee = bb;  //报错

   /*
   总结：上面三种格式中const int都可以替换成int const，只是写法不同，意义完全一样。
          例如：const int* p和int const *p是一样的。
          把const放在 * 左侧任意位置，限定了指针指向的数据不能改变；const放在 * 的右侧，限定了指针本身不能改变。
    */

    return 0;
}