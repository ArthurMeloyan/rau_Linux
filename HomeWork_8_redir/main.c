#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		printf("No program name is provided\n");
		return 1;
	}

	pid_t pid = fork();
	if (pid < 0)
	{
		perror("Unable to fork");
		return 1;
	}

	if (pid == 0)
	{
		int _out;
		for (int i = 1; i < argc; ++i)
		{
			if (strcmp(argv[i], "-out") == 0)
			{
				_out = i;
			}
		}


		int flags1 = O_WRONLY | O_CREAT;
		if (strcmp(argv[argc - 5], "-a") != 0 && strcmp(argv[argc-4], "-a") != 0)
		{
			flags1 |= O_TRUNC;
		}

		int out;
		if (strcmp(argv[argc-2], "-a") == 0)
		{
			out = open(argv[argc-4], flags1, 0666);
		}
		else
		{
			out = open(argv[argc-3], flags1, 0666);
		}
		if (out < 0)
		{
			perror("Error occurred while trying to open the file");
			return 1;
		}
		if (strcmp(argv[argc-4], "-a") == 0 || strcmp(argv[argc-5], "-a") == 0)
		{
			lseek(out, 0, SEEK_END);
		}

		for (int i = 1; i < argc; ++i)
		{
			if (strcmp(argv[i], "-out") == 0)
			{
				dup2 (out, STDOUT_FILENO);
				break;
			}
		}
		close(out);

		int flags2 = O_WRONLY | O_CREAT;
		if (strcmp(argv[argc-2], "-a") != 0)
		{
			flags2 |= O_TRUNC;
		}

		int err = open(argv[argc-1], flags2, 0666);
		if (err < 0)
		{
			perror("Error occurred while trying to open the file");
			return 1;
		}
		if (strcmp(argv[argc-2], "-a") == 0)
		{
			lseek(err, 0, SEEK_END);
		}

		for (int i = 1; i < argc; ++i)
		{
			if (strcmp(argv[i], "-err") == 0)
			{
				dup2 (err, STDERR_FILENO);
			}
		}
		close(err);

		char** args_ = malloc(sizeof(char*)* argc);
		for (int i = 1; strcmp(argv[i], "-out") != 0; ++i)
		{
			args_[i - 1] = argv[i];
		}
		args_[_out - 1] = NULL;
		execvp(argv[1], args_);

	}
	int status;
	wait(&status);
	return status;

	
}