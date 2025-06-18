#include<stdio.h>

#define ARRINTM_IMPLEMENTATION
#include "arrintm.h"



int main(){
    int array[] = {1,7,3}; 
    size_t len = (sizeof(array) / sizeof(int));

    arrprint(array,len);
    arrpop(array,&len);
    arrprint(array,len);

    arrpush(array,&len,8);
    arrprint(array,len);

    return 0;
}