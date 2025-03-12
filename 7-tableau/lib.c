#include<stdio.h>

void affiche_tabeau(int *tab,unsigned int taille){
    for (unsigned i = 0; i < taille;i++){
        printf(" tab[%u] = %d\n",i,tab[i]);
    }
}

void affiche_tableau2(int (*tab)[3], unsigned n, unsigned m){
    for (unsigned i = 0; i < n; ++i)
        for (unsigned j = 0; j < m; ++j)
            printf("tab[%u][%u] = %d\n", i, j, tab[i][j]);
}