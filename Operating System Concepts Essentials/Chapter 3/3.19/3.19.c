#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid; 

    pid = fork(); 

    if (pid < 0) /* checks if the child process was establihed properly */
    {
        printf("Failed to create fork.\n"); 
        return -1;
    }

    if (pid > 0) /* checks if the pid is bigger than 0, if true it's the parent process */
    {
        printf("Parent process with pid: %d\n", getpid()); /* prints the string to the terminal, with the parents pid */
        sleep(10);                                         
    }
    else if (pid == 0) /* checks if the pid is equal to 0, if true it's the child process */
    {
        printf("Child process with pid: %d\n", getpid()); /* prints the string to the terminal, with the child pid */
        exit(0);                                          
    }
    return 0;
}
