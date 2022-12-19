#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    int fd[2];
    

    if (pipe(fd) == -1)
    {
        perror("Pipe");
        return 1;
    }

    pid_t child1 = fork();
    pid_t child2 = fork();
    if (child1 < 0 || child2 < 0)
    {
        perror("Unable to fork");
        return 1;
    }

    close(fd[0]);
    close(fd[1]);


    if (child1 == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        if (execlp(argv[1], argv[1], NULL) == -1 )
        {
            printf("Execution of the program failed");
            return 1;
        }
        
    }

    if (child2 == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        if (execlp(argv[2], argv[2], NULL) == -1)
        {
            printf("Execution of the programm failed");
            return 1;
        }
       
    }
    
    wait(NULL);
    wait(NULL);
    
    return 0;

}