#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *ptrl, *ptr2;
	char file1[200],file2[200], c;

	printf("Please enter the file name to open for reading \n");
	scanf("%s", file1);
	printf("Please enter the file name to open for writing \n");
	scanf("%s", file2);
	
	// Open file1 for reading
	if (ptrl = fopen(file1, "r")){

	   // Open file2 for writing
	   if (ptr2 = fopen(file2, "r")){
		printf("file already exists \n");
		exit(0);
	   }else{
		ptr2 = fopen(file2, "w");
		if (ptr2 == NULL)
		{
			printf("Cannot open file %s \n", file2);
			exit(0);
		} 
		// Read contents from file 1 and write to file 2
		
		c = fgetc(ptrl);
		while (c != EOF)
		{
			fputc(c, ptr2);
			c = fgetc(ptrl);
		}

		fclose(ptrl);
		fclose(ptr2);
		printf("\nContents copied to %s", file2);
	   }
	}else{
	   printf("file doesn't exists \n");
	   exit(0); 
	}

	return 0;
} 
