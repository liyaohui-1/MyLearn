#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
 
int main(int argc, char **argv)
{
    ssize_t data_proccessed = 0;
    int pipes[2];
    const char data[] = "123";
    pid_t pid;
 
    if (pipe(pipes) == 0)
    {
        pid = fork();
        if (pid == -1)
        {
            fprintf(stderr, "Fork failure\n");
            exit(EXIT_FAILURE);
        }
 
        if (pid == 0)
        {
            // 子进程中
            // 使标准输入指向 filedes[0]
            close(0);
            dup(pipes[0]);
 
            // 关闭 pipes[0] 和 pipes[1], 只剩下标准输入
            close(pipes[0]);
            close(pipes[1]);
 
            // 启动新进程od
            execlp("od", "od", "-c", 0);
            exit(EXIT_FAILURE);
        }
        else
        {
            // 关闭 pipes[0], 因为父进程不用读取数据
            close(pipes[0]);
            data_proccessed = write(pipes[1], data, strlen(data));
 
            // 写完数据后, 关闭 pipes[1]
            close(pipes[1]);
            printf("%d -Worte %ld bytes\n", getpid(), data_proccessed);
        }
    }
    else
    {
        fprintf(stderr, "Pipe failure\n");
        exit(EXIT_FAILURE);
    }
}

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
 
// int main(int argc, char **argv)
// {
//     ssize_t data_processed = 0;
//     int filedes[2];
//     const char data[] = "Hello pipe!\n";
//     char buffer[BUFSIZ + 1];
//     pid_t pid;
 
//     // 清空缓冲区
//     memset(buffer, '\0', sizeof(buffer));
 
//     if (pipe(filedes) == 0)
//     {
//         // 创建管道成功
//         // 调用fork 创建子进程
//         pid = fork();
//         if (pid == -1)
//         {
//             fprintf(stderr, "Fork failure\n");
//             exit(EXIT_FAILURE);
//         }
 
//         if (pid == 0)
//         {
//             // 子进程
//             // 读取数据
//             data_processed = read(filedes[0], buffer, BUFSIZ);
//             printf("Read %ld bytes: %s\n", data_processed, buffer);
//             exit(EXIT_SUCCESS);
//         }
//         else
//         {
//             // 父进程
//             // 写数据
//             data_processed = write(filedes[1], data, strlen(data));
//             printf("Wrote %ld bytes: %s\n", data_processed, data);
 
//             // 休眠2秒, 主要是为了等待子进程结束, 这样做也只是纯粹为了输出好看而已
//             // 父进程其实没有必要等待子进程结束
//             sleep(2);
//             exit(EXIT_SUCCESS);
//         }
//     }
//     else
//     {
//         fprintf(stderr, "Pipe failure\n");
//         exit(EXIT_FAILURE);
//     }
// }

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
 
// int main()
// {
//     FILE *read_fp = NULL;
//     FILE *write_fp = NULL;
//     char buffer[BUFSIZ + 1];
//     int chars_read = 0;
 
//     // 初始化缓冲区
//     memset(buffer, '\0', sizeof(buffer));
     
//     // 打开ls和grep进程
//     read_fp = popen("ls -l", "r");
//     write_fp = popen("grep rwxrwxr-x", "w");
     
//     // 两个进程都打开成功
//     if (read_fp && write_fp)
//     {
//         // 读取一个数据块
//         chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
//         while (chars_read > 0)
//         {
//             buffer[chars_read] = '\0';
             
//             // 把数据写入grep进程
//             fwrite(buffer, sizeof(char), chars_read, write_fp);
             
//             // 还有数据可读，循环读取数据，直到读完所有数据
//             chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
//         }
         
//         // 关闭文件流
//         pclose(read_fp);
//         pclose(write_fp);
         
//         exit(EXIT_SUCCESS);
//     }
     
//     exit(EXIT_FAILURE);
// }