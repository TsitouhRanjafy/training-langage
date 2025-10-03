#include<stdio.h>


int compteur(void){
    static int n; // allouée une seul fois, valeur conserver, initialisation à 0

    return ++n;
}

int main(){

    printf("%d\n",compteur()); // 0 
    printf("%d\n",compteur()); // normalement c'est encore 0, mais static, alors, c'est 1 maintenant
    return 0;
}