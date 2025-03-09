#include<stdio.h>
#include<stdlib.h>

struct temps {
    unsigned int h;
    unsigned int m;
    double s;
};


int main(void){

    struct temps t;
    struct temps *p = &t;

    (*p).h = 1;
    p->m = 45;
    p->s = 30.755;

    printf("adresse de p: %d\n",&p);

    printf("\t valeur de p: %d , pointeur p: %d\n",&p[0],*(&p[0]));
    printf("\t valeur de p: %d , pointeur p: %d\n",&p[1],*(&p[1]));
    printf("\t valeur de p: %d , pointeur p: %d\n",&p[2],*(&p[2]));

    printf("\n\n\n");

    printf("adresse de h: %d\n",&(p->h));  
    printf("adresse de h: %d\n",&(p->m));  

    printf("h: %d, m: %d, s: %lf\n",*(&(p->h)),*(&(p->m)),*(&(p->s)));

    return EXIT_SUCCESS;
}