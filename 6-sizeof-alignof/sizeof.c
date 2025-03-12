#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct exemple {
    int a;
    char c;
    unsigned int population;
};

int main(){
    double f;
    size_t taille;

    taille = sizeof(_Bool);
    printf("%zu octets\n",taille);

    taille = sizeof(long double);
    printf("%zu octets\n",taille);

    taille = sizeof(short);
    printf("%zu octets\n",taille);

    taille = sizeof(long long);
    printf("%zu octets\n",taille);

    taille = sizeof(int);
    printf("%zu octets\n",taille);

    taille = sizeof(struct exemple);
    printf("%zu octets\n",taille);

    return EXIT_SUCCESS;
}