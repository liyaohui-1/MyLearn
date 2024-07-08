// #include <stdio.h>
// int sum(int n)
// {
//     int ret = 0;
//     if( n > 0 )
//     {
//         ret = n + sum(n-1);
//     }
//     return ret;
// }

// int main()
// {
//     int s = 0;
//     s = sum(10);
//     printf("sum = %d\n", s);
//     return 0;
// }



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	string temp = "123456789012345";	//注意长度 15个字节
	int *a = (int *)malloc(sizeof(int));
	int b = 0;
	for(auto &c:temp)
	{
		printf("c%p\n", &c);
	}
	printf("a%p\n", a);
	printf("b%p\n", &b);

    std::cout << "after change temp..." << std::endl;

    string tmp = "1234567890123456";	//注意长度 16个字节
	for(auto &e:tmp)
	{
		printf("e%p\n", &e);
	}
    int *f = (int *)malloc(sizeof(int));
	int g = 0;
	printf("f%p\n", f);
	printf("g%p\n", &g);

    return 0;
}

//string的所占空间大小要是大于等于16个字节，string会在堆上开辟空间；否则在栈上开辟空间。
//例子中的打印：可以看string中的地址与在栈上的地址相近，还是与堆上的地址相近，可以大概判断出其在堆上还是栈上开辟的空间。