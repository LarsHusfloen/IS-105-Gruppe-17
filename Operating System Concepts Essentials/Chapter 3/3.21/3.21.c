#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid; 
    int num, input;   

    printf("Enter the number to run: "); 
    input = scanf("%d", &num);                   
    
    /* makes sure the number is a positiv integer */
    if (num <= 0 || input != 1)
    {                                                     
        printf("The number must be a positiv integer.\n"); 
        exit(0);                                           
    }

    pid = fork(); 
    
    /* checks if the child process was establihed properly */
    if (pid < 0) 
    {
        printf("Failed to create fork.\n"); 
        return -1;
    }

    /* checks the pid for child process */
    if (pid == 0) 
    {
        printf("Start of child process\n"); 
        
        /* Calculation according to The Collatz conjecture while above 1 */
        while (num > 1)                    
        {
            printf("%d\n", num);
            
            /* Checks if num is even or odd */
            if (num % 2 == 0)    
            {
                num = num / 2; 
            }
            else if (num % 2 == 1) 
            {
                num = 3 * num + 1; 
            }
        }
        printf("%d\n", num);
        printf("The child process is done\n"); 
    }
    else
    {
        /* Parent process wait for child process to complete */
        printf("Parent process wait for child process.\n"); 
        wait(NULL);                                         
        printf("The parent process is done\n");             
    }
    return 0;
}
