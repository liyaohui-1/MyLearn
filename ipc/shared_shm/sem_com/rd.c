#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<sys/shm.h>
#include"sem.h"

int main()
{
    int shmid = shmget((key_t)1234,128,IPC_CREAT|0600);
    assert(shmid != -1);

    char* s = (char*)shmat(shmid,NULL,0);
    assert(s != NULL);
   
    sem_init();
    while(1)
    {
        sem_p(SEM2);
        if(strncmp(s,"end",3) == 0)//从这里开始就算是开始用到共享内存的东西了
        {
            break;
        }
        printf("s = %s\n",s);
        sleep(2);
        sem_v(SEM1);
    }

    shmdt(s);
    sem_destroy();
    exit(0);
}

