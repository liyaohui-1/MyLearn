#include"sem.h"

static int  semid = -1;

void sem_init()
{
    semid = semget((key_t)1234,NUM,IPC_CREAT|IPC_EXCL|0600);
    if(semid == -1)//信号量已经存在
    {
        semid = semget((key_t)1234,NUM,0600);
    }
    else//信号量不存在，信号量被创建，在这里初始化信号量
    {
        int arr[NUM]= {1,0};
        for(int i = 0; i < NUM; i++)
        {
            union semun a;
            a.val = arr[i];
        
            if(semctl(semid,i,SETVAL,a)==-1)//第一个信号量的值初始化为0
                                            //第二个信号量的值初始化为1
            {
                perror("semctl error");
            }
        }
    }
}

void sem_p(int index)
{
    struct sembuf buf;
    buf.sem_num = index;
    buf.sem_op = -1;//P
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1)==-1)
    {
        perror("semop P error");
    }
}


void sem_v(int index)
{
    struct sembuf buf;
    buf.sem_num = index;
    buf.sem_op = 1;//V
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1)==-1)
    {
        perror("semop V error");
    }
}

void sem_destroy()
{
    if(semctl(semid,0,IPC_RMID) == -1)
    {
        perror("semtcl del error");
    }
}

