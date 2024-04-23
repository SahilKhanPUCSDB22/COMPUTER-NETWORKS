#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    char* p[3] = {"ear", "mouth", "brain"};
    char* files[3] = {"etob1 < f1", "btom1 < f2", "etob1 > btom1"};
    char* args[4];
    int pid[3];
    int i = 0, re;
    while (i < 3)
    {
        args[0] = p[i];
        args[1] = files[i];
        args[2] = NULL;
        pid[i] = fork();
        if (pid[i] == -1)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (pid[i] == 0)
        {
            re = execv(p[i], args);
            if (re == -1)
            {
                perror("");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            printf("fork %d: child pid=%d\n", i, pid[i]);
        }
        i++;
    }
    return 0;
}

