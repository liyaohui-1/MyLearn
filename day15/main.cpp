/*
//setjmp和longjmp用法
#include <iostream>
#include <setjmp.h>
jmp_buf jb;
void a();
void b();
void c();

int main()
{
    if(setjmp(jb) == 0){
        a();
    }

    std::cout << "after a();" <<std::endl;
    return 0;
}

void a()
{
    b();
    std::cout << "called a();" << std::endl;
}

void b()
{
    c();
    std::cout << "called b();" << std::endl;
}

void c()
{
    std::cout << "called c();" << std::endl;
    longjmp(jb,1);
}
*/

#include <iostream>
using namespace std;

class Ex1
{

};

class Ex2
{

};

void f1()
{
    cout << "调用f1()开始" << endl;
    if(false){
        cout << "f1() called." << endl;
    }else if(true){
        throw Ex1();
    }
    cout << "调用f1()结束" << endl;
}

void f2()
{
    cout << "调用f2()开始" << endl;
    if(false){
        cout << "f2() called." << endl;
    }else if(true){
        throw Ex2();
    }
    cout << "调用f2()结束" << endl;
}

int main(int argc,char* argv[])
{
    try{
        f1();
        f2();
    }catch(Ex1 &ex){
        cout << "错误处理1" << endl;
        exit(1);
    }catch(Ex2 &ex){
        cout << "错误处理2" << endl;
        exit(2);
    }    

    return 0;
}