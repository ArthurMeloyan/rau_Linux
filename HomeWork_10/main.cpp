#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <string>


int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int res;
    int fd1[2];
    int fd2[2];
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        perror("Pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Unable to fork");
        return 1;
    }

    if (pid == 0)
    {
        close(fd1[1]);
        close(fd2[0]);
        int readCommand = 0;
        char command[1];
        while ((readCommand = read(fd1[0], command, 1)) > 0)
        {
            if (strcmp(command, "+") == 0)
            {
                res = std::atoi(argv[2]) + std::atoi(argv[3]);
                std::string str = std::to_string(res);
                const char* result = str.c_str();
                write(fd2[1], result, strlen(result));
            }
            else if (strcmp(command, "-") == 0)
            {
                res = std::atoi(argv[2]) - std::atoi(argv[3]);
                std::string str = std::to_string(res);
                const char* result = str.c_str();
                write(fd2[1], result, strlen(result));
            }
            else if (strcmp(command, "/") == 0)
            {
                res = std::atoi(argv[2]) / std::atoi(argv[3]);
                std::string str = std::to_string(res);
                const char* result = str.c_str();
                write(fd2[1], result, strlen(result));
            }
            else if (strcmp(command, "x") == 0)
            {
                res = std::atoi(argv[2]) * std::atoi(argv[3]);
                std::string str = std::to_string(res);
                const char* result = str.c_str();
                write(fd2[1], result, strlen(result));
            }
            else
            {
                write(1, "Invalid command is provided", 28);
                return 1;
            }
        }
        close(fd1[0]);
        close(fd2[1]);
    }

    close(fd1[0]);
    close(fd2[1]);
    write(fd1[1], argv[1], strlen(argv[1]));
    close(fd1[1]);
    wait(NULL);
    int readRes = 0;
    char res_[1];
    while((readRes = read(fd2[0], res_, 1)) > 0)
    {
        write(1, res_, readRes);
    }
    write(1, "\n", 1);
    close(fd2[0]);
    return 1;
}