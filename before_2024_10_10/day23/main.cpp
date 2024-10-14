#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "m:p:f:d:U")) != -1)
    {
        switch (opt)
        {
        case 'm':
            printf("Option m with value %s\n", optarg);
            break;
        case 'p':
            printf("Option p with value %s\n", optarg);
            break;
        case 'f':
            printf("Option f with value %s\n", optarg);
            break;
        case 'd':
            printf("Option d with value %s\n", optarg);
            break;
        case 'U':
            printf("Option U specified\n");
            break;
        default: /* '?' */
            fprintf(stderr,
                    "Usage: %s [-m val] [-p val] [-f val] [-d val] [-U]\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    /* 解析完所有选项后，argv[optind] 指向第一个非选项参数 */
    for (int i = optind; i < argc; i++)
    {
        printf("Non-option argument: %s\n", argv[i]);
    }

    return 0;
}