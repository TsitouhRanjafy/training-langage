#include<stdio.h>



int main(void){
    int a, b;

    printf("Entrer deux nombres :");
    scanf("%d %d",&a,&b);

    int min = (a < b) ? a:b;
    int i;

    for (i = 2;i < min; i++){
        if(a % i == 0 && b % i == 0){
            goto trouve; // 
        }
    }
    return 0;

trouve:
    printf("le plus petit diviser de %d et %d est %d ",a,b,i);
    return 0;
}
