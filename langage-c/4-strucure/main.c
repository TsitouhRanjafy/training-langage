#include<stdio.h>

struct temps{
    unsigned heurs;
    unsigned minutes;
    double secondes;
};


int main(){

    struct temps t;
    struct temps T = {
        1,
        45,
        30.560
    };
    struct temps T2 = {.minutes = 45,30 };

    printf(">");
    scanf("%d %d %lf",&t.heurs,&t.minutes,&t.secondes);
    printf("%dh %dmin %0.3lfs\n",t.heurs,t.minutes,t.secondes);

    printf("%dh %dmin %0.3lfs\n",T.heurs,T.minutes,T.secondes); // 1h 45min 30.560s

    printf("%dh %dmin %0.3lfs\n",T2.heurs,T2.minutes,T2.secondes); // 0h 45min 30.000s
    
    return 0;
}