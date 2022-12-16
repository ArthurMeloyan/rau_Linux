#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

enum{buffer_size = 256};

int main(int argc, char** argv)
{
    char buff[buffer_size];
    int file1 = open(argv[1], O_RDONLY);
    if (file1 == -1)
    {
        char* msg = strerror(errno);
        write(2, argv[1], strlen(argv[1]));
        write(2,": ", 2);
        write(2, msg, strlen(msg));
        write(2, "\n", 1);
        exit(1);
    }

    int file2 = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (file2 == -1)
    {
        char* msg = strerror(errno);
        write(2, argv[1], strlen(argv[1]));
        write(2,": ", 2);
        write(2, msg, strlen(msg));
        write(2, "\n", 1);
        exit(1);
    }

    while (read(file1, buff, sizeof(buff)) > 0)
    {
        for (int i = 0; i < sizeof(buff); ++i)
        {
            if (buff[i] >= '0' && buff[i] <= '9')
            {
                buff[i] = 'X';
            }
        }
        write(file2, buff, sizeof(buff));
    }
    close(file2);
    close(file1);
    return 0;
}