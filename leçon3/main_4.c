#include<stdio.h>


int main(){
    int a= 10;
    int *pa = &a;
    int **pp = &pa;

    printf("addresse de  a:%d valeur de  a:%d\n",&a,a);
    printf("addresse de pa:%d valeur de pa:%d pointeur pa:%d\n",&pa,pa,*pa);
    printf("addresse de pp:%d valeur de pp:%d pointeur pp:%d pointeur de pointeur pp:%d\n",&pp,pp,*pp,**pp);

    return 0;
}