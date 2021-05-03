/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.17 og 3.18 side 132 & 133 */

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
    pid_t pid;                    
    int num, input, shm_fd, size = 4096; 
    char *name = "SharedMemory";  
    
    /* Setts the pointer to be used to transfer the data to and from the shared memory */
    void *ptr;
    
    /* shm_open creates a shared memory object, parameters: name of shared memory, O_CREAT; create if it doesnt exist,
     O_RDWR; open to read and write, gives the directory permisson for the object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    
    if (shm_fd < 0)
    {                                             
        printf("Couldn't create chared memory."); 
        return -1;
    }
    
    /* Configures the size of the object in bytes */
    ftruncate(shm_fd, size);
    
    /* Establishes a memory mapped file containing the shared memory object,
     also returns a pointer to the file that is used to access the memory object */
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0); 

    printf("Enter a positiv number to run through The Collatz conjecture: "); 
    input = scanf("%d", &num);                                                        
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
            /* Writes to the shared memory object */
            sprintf(ptr, "%d\n", num);   
            
            /* Calculates the length of num, e.g. 22 = 2, 123 = 3. Includes space for \n */
            int length = log10(num) + 2; 
            
            /* Increments the pointer */
            ptr += length;               
            
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
        /* Writes to the shared memory object */
        sprintf(ptr, "%d\n", num);             
        printf("The child process is done\n"); 
    }
    else
    {
        /* Parent process wait for child process to complete */
        printf("Parent process wait for child process.\n"); 
        wait(NULL);                                         
        
        /* Read/print from the shared memory object */
        printf("Parent:\n%s", (char *)ptr);                 

        printf("The parent process is done\n"); 
        
        /* Removes the shared memory object */
        shm_unlink(name);                       
    }
    return 0;
}
