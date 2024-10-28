#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<sys/shm.h>

int main()
{
    int shmid = shmget((key_t)1234,128,IPC_CREAT|0600);
    assert(shmid != -1);

    char* s = (char*)shmat(shmid,NULL,0);
    assert(s != NULL);

    printf("shmb s = %s\n",s);

    shmdt(s);
    exit(0);
}
