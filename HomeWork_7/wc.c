#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("No program name is provided\n");
        return 1;
    }

    if (argc == 2)
    {
        printf("No options are provided\n");
        return 1;
    }

    if (argc > 3)
    {
        printf("Too much arguments are provided\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Unable to fork\n");
        return 1;
    }

    if (pid == 0)
    {
        if(execlp("wc", "wc", argv[1], argv[2], NULL) == -1)
        {
            printf("Problem occurred while executing the programm\n");
            exit(1);
        }
        exit(0);
    }
    return 0;
}