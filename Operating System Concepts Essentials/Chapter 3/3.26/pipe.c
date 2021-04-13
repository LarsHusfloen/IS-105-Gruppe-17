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
	int size = 100, i, fd[2];				 /* defines variables of the type integer, and their value */
	char write_msg[size], read_msg[size];	 /* defines variable of the type char and their buffer size */
	pid_t pid;								 /* defines pid as the name of variable of the type pid_t */
	printf("Enter the string to reverse: "); /* prints the string to the terminal */
	fgets(write_msg, size, stdin);			 /* Assignes standard input to write_msg */
	write_msg[strcspn(write_msg, "\n")] = 0; /* Cleares the input buffer */

	if (pipe(fd) == -1) /* create the pipe */
	{
		printf("Failed tp create pipe.\n"); /* prints the string to the terminal */
		return 1;
	}

	pid = fork(); /* makes a child process and stores it's id to pid */
	if (pid < 0)  /* checks if the child process was establihed properly */
	{
		printf("Failed to create fork.\n"); /* prints the string to the terminal */
		return -1;
	}

	if (pid == 0) /* checks if the pid is equal to 0, if true it's the child process */
	{
		printf("Start of child process\n");	   /* prints the string to the terminal */
		read(fd[READ_END], read_msg, size);	   /* reads from pipe and assignes it to read_msg */
		close(fd[READ_END]);				   /* closes one side of the pipe*/
		for (i = 0; i < strlen(read_msg); i++) /* convert from upper to lowercase and vice versa */
		{
			if (islower(read_msg[i])) /* Check if it is lowercase */
			{
				write_msg[i] = toupper(read_msg[i]); /* Convert to uppercase */
			}
			else
			{
				write_msg[i] = tolower(read_msg[i]); /* Convert to lowercase */
			}
		}
		write(fd[WRITE_END], write_msg, size); /* Writes the new msg to the pipe */
		close(fd[WRITE_END]);				   /* Closes the final side of the pipe */
		printf("The child process is done\n"); /* prints the string to the terminal */
	}
	else
	{
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); /* Writes the input from terminal into the pipe */
		printf("Written to the pipe: %s\n", write_msg);			/* prints the string to the terminal */
		close(fd[WRITE_END]);									/* closes one side of the pipe*/

		printf("Parent process wait for child process.\n"); /* prints the string to the terminal */
		wait(NULL);											/* Parent process wait for child process to complete */
		read(fd[READ_END], read_msg, size);					/* reads from pipe and assignes it to read_msg */
		printf("Reading from the pipe: %s\n", read_msg);	/* Prints the new message to the terminal */
		close(fd[READ_END]);								/* Closes the final side of the pipe */
		printf("The parent process is done\n");				/* prints the string to the terminal */
	}
	return 0;
}