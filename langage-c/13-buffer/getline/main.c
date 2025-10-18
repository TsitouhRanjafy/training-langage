#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE * fptr;
    char * line = NULL;
    size_t len = 1024; // de tout façon, getline va faire realloc si cette len ne suffit pas comme buffer
    ssize_t read;

    fptr = fopen("/etc/motd","r");
    if (fptr == NULL) 
        exit(EXIT_FAILURE);
    
    while ((read = getline(&line, &len, fptr)) != -1) {
        printf("Réception d'une ligne de longueur %zu :\n", read);
        printf("%s", line);
    }

    if (line) 
        free(line);
    return EXIT_SUCCESS;
}