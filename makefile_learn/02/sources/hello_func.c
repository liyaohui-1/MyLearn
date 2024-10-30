#include <stdio.h>
#include "hello_func.h"

void hello_func(void)
{
    printf("hello, world! This is a C program.\n");
    for (int i=0; i<11; i++ ) {
        printf("output i=%d\n",i);
    }
}