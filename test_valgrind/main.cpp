/*
    可能丢失(definitely lost)
    在 test04 中，我们 new 一个数组并返回给局部变量 data，随后声明静态指针 p 并指向数组第二个元素的地址，test04
    测试结束后直到 main 函数返回前，静态指针 p 仍然可获得，但是 p 已经不再指向数组的起始地址。Memcheck
    认为指向这块内存的指针可能已经丢失，会报告 possibly lost 错误。 使用valgrind --leak-check=full
   --show-reachable=yes./test_v 命令，

*/

void test04()
{
    char* data = new char[1024];
    static char* p = data + 1;
}

int main()
{
    test04();
    return 0;
}

/*
    间接丢失(indirectly lost)
    test03 测试结束后，局部变量 obj 丢失，内存未被释放且其内部成员 _p 指针也间接丢失，没有被释放
    使用valgrind --leak-check=full  --show-reachable=yes./test_v 命令，
    可以看到valgrind检测到了内存泄漏。
*/

// class Object
// {
// public:
//     Object() { _p = new char[1024]; }
//     ~Object()
//     {
//         if (_p)
//             delete _p;
//     }

// private:
//     char* _p = nullptr;
// };

// void test03() { Object* obj = new Object(); };

// int main()
// {
//     test03();
//     return 0;
// }


/*
    绝对丢失(definitely lost)
    使用valgrind --leak-check=full  --show-reachable=yes ./test_v 命令，
    可以插入如下代码中test01中未释放的内存，
    test02中申请的动态内存赋值给静态指针，main函数返回前，静态指针未释放，
*/
// void test01() { char* p = new char[1024]; }

// void test02() { static char* p = new char[1024]; }

// int main()
// {
//     test01();
//     test02();
//     return 0;
// }
