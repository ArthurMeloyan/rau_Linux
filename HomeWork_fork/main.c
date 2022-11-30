#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <locale.h>
#include <string.h>
#define STRING_PATTERN  "%s\n"
#define NUMERIC_PATTERN "%d\n"



int main(int argc, char** argv)
{

   setlocale(LC_ALL, "Russian");
   int count = 0;
   if (argc == 1)
   {
    printf("You did not provide me any arguments, damn!\n");
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
    printf("Привет, мама, я твой сын и я посчитал avarage of the command line arguments:");
    for (int i = 1; i < argc; ++i)
    {
        count += atoi(argv[i]);
    }
    int res = count / (argc - 1);
    printf("%d\n", res);
    printf("Остаток: %d", res%(argc -1));
    return 0;
   }
   if (argc > 1)
   {
    printf("Жду сыночка:-(\n");
    wait(NULL);
   }
   
}
