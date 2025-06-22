#include<stdio.h>


int main(){

    char buffer[50];
    char *s = "geeksforgeeks";

    printf("Writing %s onto buffer"
        " with capacity 6",
        s);

    int j = snprintf(buffer, 50, "%s",s);

    printf("\n j = %d\n",j);
    printf("string written on buffer = %s\n",buffer);
    return 0;
}