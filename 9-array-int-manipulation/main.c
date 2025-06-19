#include<stdio.h>

#define ARRINTM_IMPLEMENTATION
#include "arrintm.h"



int main(){
    int array[100] = {7,-4,12};
    size_t len = 3;
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrinsert(array,&len,0,1);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrinsert(array,&len,2,3);
    arrprint(array,len);
    printf("len: %d\n\n",len);
    
    arrpush(array,&len,-1);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrremove(array,&len,3);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrremove(array,&len,0);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrremove(array,&len,3);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrpop(array,&len);
    arrprint(array,len);
    printf("len: %d\n\n",len);

    arrremove(array,&len,1);
    arrprint(array,len);
    printf("len: %d\n\n",len);
    return 0;
}