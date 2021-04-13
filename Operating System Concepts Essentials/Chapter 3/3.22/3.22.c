#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <math.h>

int main()
{
    pid_t pid;                    /* defines pid as the name of variable of the type pid_t */
    int num, shm_fd, size = 4096; /* defines variables of the type integer, and setts the value of size to 4096 */
    char *name = "SharedMemory";  /* Defines the name to be used */
    void *ptr;                    /* Setts the pointer to be used to transfer the data to and from the shared memory */

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    /* shm_open creates a shared memory object, parameters: name of shared memory, O_CREAT; create if it doesnt exist,
     O_RDWR; open to read and write, gives the directory permisson for the object */
    if (shm_fd < 0)
    {                                             /* Checks if the memory object was created succsesfully */
        printf("Couldn't create chared memory."); /* prints the string to the terminal */
        return -1;
    }
    ftruncate(shm_fd, size);                                /* Configures the size of the object in bytes */
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0); /* Establishes a memory mapped file containing the shared memory object,
     also returns a pointer to the file that is used to access the memory object */

    printf("Enter a positiv number to run through The Collatz conjecture: "); /* prints the string to the terminal */
    scanf("%d", &num);                                                        /* takes the input and setts the value to num */
    if (num <= 0)
    {                                                      /* Checks if the input is a positive integer */
        printf("The number must be a positiv integer.\n"); /* Prints the string in terminal */
        exit(0);                                           /* Exits the program */
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

        while (num > 1) /* Ensures that the following code will run as long as num is higher than 1, therefor it stops when num reaches 1 */
        {
            sprintf(ptr, "%d\n", num);   /* Writes to the shared memory object */
            int length = log10(num) + 2; /* Calculates the length of num, e.g. 22 = 2, 123 = 3. Includes space for \n */
            ptr += length;               /* Increments the pointer */
            if (num % 2 == 0)            /* Checks if num is even or odd, if true num is even */
            {
                num = num / 2; /* Calculation according to The Collatz conjecture */
            }
            else if (num % 2 == 1) /* Checks if num is even or odd, if true num is odd */
            {
                num = 3 * num + 1; /* Calculation according to The Collatz conjecture */
            }
        }
        sprintf(ptr, "%d\n", num);             /* Writes to the shared memory object */
        printf("The child process is done\n"); /* prints the string to the terminal */
    }
    else
    {
        printf("Parent process wait for child process.\n"); /* prints the string to the terminal */
        wait(NULL);                                         /* Parent process wait for child process to complete */
        printf("Parent:\n%s", (char *)ptr);                 /* Read/print from the shared memory object */

        printf("The parent process is done\n"); /* prints the string to the terminal */
        shm_unlink(name);                       /* Removes the shared memory object */
    }
    return 0;
}