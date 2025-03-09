#include<stdio.h>


// fonction qui retourne un pointeur
int *ptr(void){
    static int n = 10; // tsy mety vao tsy static, ici https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4277_les-pointeurs/#2-declaration-et-initialisation

    return &n;  
}

int main(){
    int *p = ptr();

    printf("%d\n",*p);
    return 0;
}