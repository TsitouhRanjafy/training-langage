#include<stdio.h>
#include<stdlib.h>

struct temps {
    unsigned h;
    unsigned m;
    double s;
};


int main(void){

    struct temps t;
    struct temps *p = &t;

    (*p).h = 1;
    p->m = 45;
    p->s = 30.755;

    printf("adresse de p: %d\n",&p);

    printf("\t valeur de p: %d : %d, pointeur p: %d\n",&p[0],p,*(&p[0]));
    printf("\t valeur de p: %d : %d, pointeur p: %d\n",&p[1],p,*(&p[1]));
    printf("\t valeur de p: %d : %d, pointeur p: %d\n",&p[2],p,*(&p[2]));
    printf("\t valeur de p: %d : %d\n",&p[3],p);
    printf("\n\n\n");
    printf("adresse de h: %d\n",&(p->h));  
    printf("adresse de h: %d\n",&(p->m));  

    return EXIT_SUCCESS;
}