#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  // print the process pid 
  printf("\n process pid: %d\n", getpid());
  
  const char * message = "Loading";
  
  int cpt = 1;
  printf(" %s", message);
  while(1){
    printf(".");
    // synchonise output
    fflush(stdout);
    sleep(1);
    if (cpt == 3) {
      printf("\r           ");
      printf("\r %s", message);
      fflush(stdout);
      sleep(1);
      cpt = 0;
    }
    cpt++;
  }
  return 0;
}