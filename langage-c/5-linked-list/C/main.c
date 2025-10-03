#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"header.h"


int main(){

    struct Personne *head = NULL;
    struct Personne *last = NULL;
    int inputNumber,position;
    char choise;

    printf("e: Empiler, d: Depile, s: Enlever, i: Inserer");
    do{
        printf("\n\n [e/d/s/i]: "); scanf(" %c",&choise);

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
            case 'i':
                printf("\t entrer le numero> "); scanf("%d",&inputNumber);
                printf("\t inserer après? : "); scanf(" %d",&position);
                inserer(&head,position,inputNumber);
                break;
            default:
                printf("mauvaise");
                break;
        }
        afficher(&head);
    } while(choise != 'c');
    
    return EXIT_SUCCESS;
}

