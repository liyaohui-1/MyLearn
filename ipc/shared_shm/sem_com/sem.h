#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<sys/sem.h>

#define SEM1 0
#define SEM2 1

#define NUM 2

union semun
{
    int val;
};

void sem_init();//创建或者初始化信号量
void sem_p(int index);//p操作，信号量减一
void sem_v(int index);//v操作，信号量加一
void sem_destroy();//销毁信号量

