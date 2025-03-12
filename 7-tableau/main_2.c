#include<stdio.h>
#include<stdlib.h>
#include "lib.h"


int main(void){

    int tab[2][3] = {{0,1,3},{3,5,6}};
    int t2[][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };


    affiche_tableau2(tab,2,3);
    return EXIT_SUCCESS;
}