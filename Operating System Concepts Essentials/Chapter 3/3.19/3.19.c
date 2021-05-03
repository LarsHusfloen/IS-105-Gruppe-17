#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid; 

    pid = fork(); 

    /* checks if the child process was establihed properly */
    if (pid < 0) 
    {
        printf("Failed to create fork.\n"); 
        return -1;
    }

    /* checks if the pid corresponds with parent or child process */
    if (pid > 0) 
    {
        printf("Parent process with pid: %d\n", getpid());
        sleep(10);                                         
    }
    else if (pid == 0) 
    {
        printf("Child process with pid: %d\n", getpid());
        exit(0);                                          
    }
    return 0;
}
