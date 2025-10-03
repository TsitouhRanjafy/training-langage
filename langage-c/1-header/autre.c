#include<stdio.h>
#include "autre2.h"

int n = 10;

int triple(int nombre){
    return (nombre * 3);
}


// cette fonction ne pourrais pas importer dans un autre fichier, même avec externe
static void welcom(void){
    printf("bonjour autre.c\n");
}
