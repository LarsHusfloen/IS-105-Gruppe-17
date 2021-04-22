#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid; 
    int num;   

    printf("Enter the number to run: "); 
    scanf("%d", &num);                   
    if (num <= 0)
    {                                                      /* Checks if the input is a positive integer */
        printf("The number must be a positiv integer.\n"); /
        exit(0);                                           
    }

    pid = fork(); 

    if (pid < 0) /* checks if the child process was establihed properly */
    {
        printf("Failed to create fork.\n"); 
        return -1;
    }

    if (pid == 0) /* checks if the pid is equal to 0, if true it's the child process */
    {
        printf("Start of child process\n"); 
        while (num > 1)                     /* Ensures that the following code will run as long as num is higher than 1, therefor it stops when num reaches 1 */
        {
            printf("%d\n", num); /* Prints the value of num for every loop */
            if (num % 2 == 0)    /* Checks if num is even or odd, if true num is even */
            {
                num = num / 2; /* Calculation according to The Collatz conjecture */
            }
            else if (num % 2 == 1) /* Checks if num is even or odd, if true num is odd */
            {
                num = 3 * num + 1; /* Calculation according to The Collatz conjecture */
            }
        }
        printf("%d\n", num);                   /* Prints the value of num */
        printf("The child process is done\n"); 
    }
    else
    {
        printf("Parent process wait for child process.\n"); 
        wait(NULL);                                         /* Parent process wait for child process to complete */
        printf("The parent process is done\n");             
    }
    return 0;
}
