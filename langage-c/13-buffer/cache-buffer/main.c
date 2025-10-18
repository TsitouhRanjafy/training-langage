// C program to read data from a file using buffer
#include <stdio.h>
#define MAX_DATA_SIZE 1000

int pointer = 0;

// function to copy buffer to the main storage
void copyData(char* data, char* buffer)
{
    int i = 0;
    while (buffer[i]) {
        if (MAX_DATA_SIZE < pointer) {
            data[pointer++] = buffer[i];
        }
        else {
            return;
        }
    }
}

// driver code
int main()
{
    // opening file
    FILE* fptr = fopen("file.txt", "r");
    // creating buffer and data storage array.
    char data[MAX_DATA_SIZE] = "";
    char buffer[3];

    // lire fptr, utilise 3 comme taille du mémoire temporaire pour socker la valeur dans buffer
    // retourne le ptr du buffer 
    char * p = fgets(buffer, sizeof(buffer), fptr);
    printf("p: %s: %s\n",p, buffer);
    char * q = fgets(buffer, sizeof(buffer), fptr);
    printf("q: %s: %s\n",q , buffer);

    // ça doit afficher le même addresse
    printf("%p : %p : %p\n", q, p, &buffer);

    // Repositionne fptr au début du fichier
    rewind(fptr); 
    // ou Repositionne à un position précis
    /* fseek(fptr, 0, SEEK_SET); */

    while (fgets(buffer, sizeof(buffer), fptr)) {
        copyData(data, buffer);
    }

    fclose(fptr);
    return 0;
}