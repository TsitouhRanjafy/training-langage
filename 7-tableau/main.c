#include<stdio.h>
#include<stdlib.h>
#include "lib.c"

struct temps {
    unsigned h;
    unsigned m;
    double s;
};


int main(void){
    int tab[3] = { [2] = 3 }; // 0 0 3
    int tab1[] = { [0] = 42, [1] = 64, [99] = 100 }; 
    struct temps tab2[2] = { { 12, 45, 50.6401 }, { 13, 30, 35.480 } } ; 

    printf("%d | %d | %d |\n",tab[0],tab[1],tab[2]);


    int tableau[5] = { 784, 5, 45, -12001, 8 };
    int somme = 0;  

    affiche_tabeau(tableau,5);
    for (unsigned i = 0; i <= 5; i++){
        somme += tableau[i];
    }

    printf("somme: %d",somme);  
    return EXIT_SUCCESS;
}

