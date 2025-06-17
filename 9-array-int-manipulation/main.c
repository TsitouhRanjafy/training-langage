#include<stdio.h>

#define ARRINTM_IMPLEMENTATION
#include "arrintm.h"


int main(){
    int array[] = {1,7,3,4,7}; 

    int *ptr_array = array;

    // printf(": %d",sizeof(array) / 4);
    // for (size_t i = 0; i <= 7; ++i){
    //     printf(": %d",array[i]);
    //     printf(": %d :\n",*(&ptr_array[i]));
    // }

    return 0;
}