#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Invalid amount of arguments\n");
        return 1;
    }

    pid_t pid = fork();
    int out[2];
    int input[2];
    if (pipe(out) == -1 || pipe(input) == -1)
    {
        perror("Pipe");
        return 1;
    }

    if (pid < 0)
    {
        perror("Unable to fork");
        return 1;
    }

    if (pid == 0)
    {
        close(input[1]);
        dup2(input[0], 0);
        if(execlp(argv[1], argv[1], NULL) == -1)
        {
            printf("Execution of the programm failed\n");
            return 1;
        }
        close(input[0]);
        close(out[0]);
        dup2(out[1], 1);
       if (execlp(argv[2], argv[2], NULL) == -1)
       {
            printf("Execution of the programm failed\n");
            return 1;
       }
        close(out[1]);
    }

    wait(NULL);
    return 0;
}