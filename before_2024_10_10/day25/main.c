#include <stdio.h>
#include <stdint.h>

int main(int argc,char* argv[])
{
    uint32_t a = 8;
    printf("a = %d.\n",(a &0x08) >> 3);
    return 0;
}