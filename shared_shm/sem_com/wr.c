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
        char buff[128] = {0};
        printf("input:\n");
        fgets(buff,128,stdin);

        sem_p(SEM1);
        strcpy(s,buff);//临界区
        sem_v(SEM2);

        if(strncmp(buff,"end",3) == 0)
        {
            break;
        }
    }

    shmdt(s);
    exit(0);
}

