#include<stdio.h>


int main(){
    int a = 2;
    int *n = &a;

    printf("addresse de a:%d value:%d\n",&a,a);
    printf("addresse de n:%d value:%d valueOfvalue: %d",&n,n,*n);

    return 0;
}