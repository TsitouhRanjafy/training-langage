#include<stdio.h>
#include<errno.h>
#include<math.h>


int main(void){
    errno = 0;
    double value,puissance;

    while(scanf("%lf %lf",&value,&puissance) != 2){
        printf("Réssayer\n");
    }

    printf(" %0.2f^%0.2f=",value,puissance);
    double x = pow(value,puissance);
    if (errno == 0)
        printf(" %0.3f",x);
    else
        printf("Invalide");
    return 0;
}