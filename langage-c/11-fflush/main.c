#include<stdio.h>
#include<stdlib.h>

int main(){
  int returnCode;
  int count;
  int index = 0;
  
  printf("Contact count to insert:"); scanf("%d", &count);
  printf("  count insered: %d\n",count);
  
  // open file as writing access
  FILE * stream = fopen("/data/data/com.termux/files/home/Contacts.txt","w");
  if (stream == NULL) {
    fprintf(stderr, "Cannot open file for writing");
    exit(-1);
  } else {
    printf("  file opened with success\n");
  }
  
  
  while (index < count) {
    char name[30];
    char phoneNum[30];
    printf("  enter name:"); scanf("%s",name);
    printf("  enter phone number:"); scanf("%s",phoneNum);
    
    // print name and phone number in stream
    fprintf(stream, "| %-30s | %-30s \n", name, phoneNum);
    
    // display the file between each insertion.
    // ou synchoniser le fichier a chaque insertion
    if (fflush(stream)) {
      fprintf(stderr, " Cannot flush the file\n");
      break;
    }
    index += 1;
  }

  // close the file
  returnCode = fclose(stream);
  if (returnCode == EOF) {
    fprintf(stderr, " Cannot close file\n");
    exit(-1);
  }
  printf(" file closed\n");
  return 0;
}