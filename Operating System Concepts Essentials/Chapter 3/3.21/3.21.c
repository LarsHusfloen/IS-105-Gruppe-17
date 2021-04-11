#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid; /* defines pid as the name of variable of the type pid_t */
    int num; /* defines num as the name of variable of the type integer */

    printf("Enter the number to run: "); /* prints the string to the terminal */
    scanf("%d", &num); /* takes the input and setts the value to num */
    if(num <= 0){ /* Checks if the input is a positive integer */
        printf("The number must be a positiv integer.\n"); /* Prints the string in terminal */
        exit(0); /* Exits the program */
    }

    pid = fork(); /* makes a child process and stores it's id to pid */

    if (pid < 0) /* checks if the child process was establihed properly */
    {
        printf("Failed to create fork.\n"); /* prints the string to the terminal */
        return -1; 
    }

    if (pid == 0) /* checks if the pid is equal to 0, if true it's the child process */
    { 
        printf("Start of child process\n"); /* prints the string to the terminal */
        while(num > 1) /* Ensures that the following code will run as long as num is higher than 1, therefor it stops when num reaches 1 */
        {
            printf("%d\n", num); /* Prints the value of num for every loop */
            if(num % 2 == 0) /* Checks if num is even or odd, if true num is even */
            {
                num = num / 2; /* Calculation according to The Collatz conjecture */
            } 
            else if(num % 2 == 1) /* Checks if num is even or odd, if true num is odd */
            {
                num = 3 * num + 1; /* Calculation according to The Collatz conjecture */
            }
        } 
        printf("%d\n", num); /* Prints the value of num */
        printf("The child process is done\n"); /* prints the string to the terminal */
    } else
        {
            printf("Parent process wait for child process.\n"); /* prints the string to the terminal */
            wait(NULL); /* Parent process wait for child process to complete */
            printf("The parent process is done\n"); /* prints the string to the terminal */
        } 
    return 0; 
}