
#include <stdio.h>


int main(void){
    int x;
    int y;

    printf("Entrez deux nombres : ");

    if (scanf("%d %d", &x, &y) == 2)
        printf("Vous avez entre : %d et %d\n", x, y);

}