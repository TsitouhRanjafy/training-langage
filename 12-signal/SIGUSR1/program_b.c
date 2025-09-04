#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

int main(int c, char * argv[]){
  // Get program arguement
  pid_t pid = atoi(argv[1]);
  
  // Send the signal to the specified proces by porcess id (pid) 
  kill(pid, SIGUSR1);
  
  printf("Sent signal to process %d\n",pid);
  return 0;
}