/* Deler av kode hentet eller modifisert fra 
Silverschatz figure 3.25 & 3.26 side 143 & 144 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define READ_END 0
#define WRITE_END 1

int main()
{
	int size = 100, i, fd[2];				 
	char write_msg[size], read_msg[size];	 
	pid_t pid;								 
	printf("Enter the string to reverse: "); 
	fgets(write_msg, size, stdin);			
	
	/* Cleares the input buffer */
	write_msg[strcspn(write_msg, "\n")] = 0; 	

	/* create the pipe and chechs if it was created correctly*/
	if (pipe(fd) == -1) 	
	{
		printf("Failed tp create pipe.\n"); 
		return 1;
	}

	pid = fork(); 
	if (pid < 0)
	{
		printf("Failed to create fork.\n"); 
		return -1;
	}
	
	/* checks the pid for child process */
	if (pid == 0) 
	{
		printf("Start of child process\n");	   
		
		/* reads from pipe and assignes it to read_msg */
		read(fd[READ_END], read_msg, size);	
		
		/* closes one side of the pipe*/
		close(fd[READ_END]);			
		
		/* convert from upper to lowercase and vice versa */
		for (i = 0; i < strlen(read_msg); i++) 	
		{
			if (islower(read_msg[i])) 	
			{
				write_msg[i] = toupper(read_msg[i]); 
			}
			else
			{
				write_msg[i] = tolower(read_msg[i]); 
			}
		}
		
		/* Writes the new msg to the pipe and closes the final side of the pipe*/
		write(fd[WRITE_END], write_msg, size); 		
		close(fd[WRITE_END]);				
		printf("The child process is done\n"); 
	}
	else
	{
		/* Writes the input from terminal into the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); 	
		printf("Written to the pipe: %s\n", write_msg);			
		
		/* closes one side of the pipe*/
		close(fd[WRITE_END]);						

		printf("Parent process wait for child process.\n"); 
		wait(NULL);							
		
		/* reads from pipe and assignes it to read_msg */
		read(fd[READ_END], read_msg, size);				
		printf("Reading from the pipe: %s\n", read_msg);	
		
		/* Closes the final side of the pipe */
		close(fd[READ_END]);						
		printf("The parent process is done\n");				
	}
	return 0;
}
