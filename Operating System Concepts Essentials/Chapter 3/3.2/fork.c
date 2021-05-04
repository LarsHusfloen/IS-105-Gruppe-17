/* Koden hentet fra Silverschatz
 figure 3.31 side 150 */

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>

int main() {
   
   fork();
   
   fork();
   
   fork();
   /* Writes process in the terminal for every process */
   printf("process\n");
   return 0;
}