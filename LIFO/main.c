#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"header.h"


int main(){

    struct Personne *head = NULL;
    struct Personne *last = NULL;
    int inputNumber,count;
    char choise;

    do{
        printf("\n e: Empiler, d: Depile, s: Enlever [e/d/s]: "); scanf(" %c",&choise);

        switch (choise){
            case 'e': 
                printf("\t entrer le numero> "); 
                scanf(" %d",&inputNumber);
                empiler(&head,&last,inputNumber);
                break;
            case 'd':
                depiler(&head,&last);
                break;
            case 's':
                printf("\t entrer le numero> "); scanf(" %d",&inputNumber);
                enlever(&head,inputNumber);
                break;
            default:
                printf("mauvaise\n");
                break;
        }
        afficher(&head);
    } while(choise != 'c');
    
    return EXIT_SUCCESS;
}

