#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("No program name is provided\n");
        return 1;
    }
    int status;

    for (int i = 1; i < argc; ++i)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            printf("Unable to fork\n");
            return 1;
        }

        
        if (pid == 0)
        {
            char* child_args[] = {argv[i], NULL};
            if (execvp(argv[i], child_args) == -1)
            {
                printf("%s: %s\n",argv[i], "Command not found");
                exit(1);
            }
            else
            {
                exit(0);
            }
        }
        wait(&status);
        if (status != 0)
            break;

    }
}