#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
 
static int alarm_fired = 0;
 
void ouch(int sig)
{
    alarm_fired = 1;
}
 
int main()
{
    // 关联信号处理函数
    signal(SIGALRM, ouch);
     
    // 调用alarm函数，5秒后发送信号SIGALRM
    alarm(5);
     
    // 挂起进程
    pause();
     
    // 接收到信号后，恢复正常执行
    if(alarm_fired == 1)
    {
        printf("Receive a signal %d\n", SIGALRM);
    }
 
    exit(0);
}

// #include <unistd.h>
// #include <sys/types.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <signal.h>
 
// static int alarm_fired = 0;
 
// void ouch(int sig)
// {
//     alarm_fired = 1;
// }
 
// int main()
// {
//     pid_t pid;
//     pid = fork();
//     switch(pid)
//     {
//     case -1:
//         perror("fork failed\n");
//         exit(1);
//     case 0:
//         // 子进程
//         sleep(5);
         
//         // 向父进程发送信号
//         kill(getppid(), SIGALRM);
//         exit(0);
//     default:;
//     }
     
//      // 设置处理函数
//     signal(SIGALRM, ouch);
//     while(!alarm_fired)
//     {
//         printf("Hello World!\n");
//         sleep(1);
//     }
//     if(alarm_fired)
//         printf("\nI got a signal %d\n", SIGALRM);
 
//     exit(0);
// }

// #include <unistd.h>
// #include <stdio.h>
// #include <signal.h>
 
// void ouch(int sig)
// {
//     printf("\nOUCH! - I got signal %d\n", sig);
// }
 
// int main()
// {
//     struct sigaction act;
//     act.sa_handler = ouch;
     
//     // 创建空的信号屏蔽字，即不屏蔽任何信息
//     sigemptyset(&act.sa_mask);
     
//     // 使sigaction函数重置为默认行为
//     act.sa_flags = SA_RESETHAND;
 
//     sigaction(SIGINT, &act, 0);
 
//     while(1)
//     {
//         printf("Hello World!\n");
//         sleep(1);
//     }
 
//     return 0;
// }

// #include <signal.h>
// #include <stdio.h>
// #include <unistd.h>

// void ouch(int sig)
// {
//     printf("\nOUCH! - I got signal %d\n", sig);

//     // 恢复终端中断信号SIGINT的默认行为
//     (void)signal(SIGINT, SIG_IGN);
// }

// int main()
// {
//     // 改变终端中断信号SIGINT的默认行为，使之执行ouch函数
//     // 而不是终止程序的执行
//     (void)signal(SIGINT, ouch);
//     while (1) {
//         printf("Hello World!\n");
//         sleep(1);
//     }

//     return 0;
// }