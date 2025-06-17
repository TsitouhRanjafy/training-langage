#ifndef ARRINTM_H
#define ARRINTM_H

/*
    This is a single header-only-file library that provides easy to manipulate array of int

    To use this library, do this in *one* C file:
        #define ARRINTM_IMPLEMENTATION
        #include "arrintm.h"

    DOCS
        Functions

            arrprint(int *arr);
              print the array

*/

#include<stdio.h>

void  test();

// Implémentation; compilé uniquemennt si STAIM_IMPLEMENTATION est défini
#ifdef ARRINTM_IMPLEMENTATION

void arrprint(int *arr){
    
    printf("%d", sizeof(arr[2]));
    // for (size_t i = 0; i < (sizeof(arr) / 4); ++i){

    // }
}

void test(){
    printf("okok");
}

#endif

#endif