#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>




bool lire_ligne(char * chaine, size_t max){
    size_t i;

    for (i = 0; i < max; i ++){
        char c;
        if (scanf("%c",&c) != 1){
            return false;
        } else if (c == '\n'){
            break;
        }
        chaine[i] = c;
    }

    chaine[i] = '\0';
    return true;
}

int main(void){


    char c = 'o';
    char mot[255];
    bool boolean;

    boolean = isalnum(c);

    printf("%d\n",boolean);

    printf("Quel est votre nom? >");
    if (scanf("%254s",mot) != 1){
        printf("Erreur lors de la saisie\n");
        return EXIT_FAILURE;
    }
    printf("Bien le bonjour %s \n",mot);

    while (getchar() != '\n'); // La condition != '\n' signifie "lire et ignorer les caractères jusqu'à atteindre un saut de ligne (\n)".
    printf("Entrer un phrase de 254 caractère max >");
    
    lire_ligne(mot,sizeof(mot));

    printf("\n\t      %s",mot);
    return EXIT_SUCCESS;
}


/**
 * 
int isalnum(int c);
int isalpha(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
 */