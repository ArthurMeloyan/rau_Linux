#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("No programm name is provided\n");
        return 1;
    }

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
            if (execlp("cat","cat", argv[i]) == -1)
            {
                printf("%s: %s\n", argv[i], " Command not found");
                exit(1);
            }
            exit(0);
        }
    }
    
}