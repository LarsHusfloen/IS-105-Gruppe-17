#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid; /* defines pid as the name of variable of the type pid_t */

    pid = fork(); /* makes a child process and stores it's id to pid */

    if (pid < 0) /* checks if the child process was establihed properly */
    {
        printf("Failed to create fork.\n"); /* prints the string to the terminal */
        return -1; 
    }

    if (pid > 0) /* checks if the pid is bigger than 0, if true it's the parent process */
    { 
        printf("Parent process with pid: %d\n", getpid()); /* prints the string to the terminal, with the parents pid */
        sleep(10); /* sleep for 10 seconds */
    }
    else if (pid == 0) /* checks if the pid is equal to 0, if true it's the child process */
    { 
        printf("Child process with pid: %d\n", getpid()); /* prints the string to the terminal, with the child pid */
        exit(0); /* closes the child processen */
    }
    return 0; 
}