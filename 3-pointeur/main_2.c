#include<stdio.h>

// peut modifier la valeur de la variable
void test(int *pa,int *pb){
    *pa = 10;
    *pb = 20;
}

// ne modifier pas la valeur de la variable
void test2(int a,int b){
    a = 2;
    b = 3;
}

int main(){
    int a,b;
    int *pa = &a;
    int *pb = &b;

    test(&a,&b);
    // ou 
    test(pa,pb); 
    printf("a=%d b=%d ",a,b);
    return 0;
}