#ifndef ARRINTM_H
#define ARRINTM_H

/*
    This is a single header-only-file library that provides easy to manipulate array of int

    To use this library, do this in *one* C file:
        #define ARRINTM_IMPLEMENTATION
        #include "arrintm.h"

    DOCS
        Functions

            arrprint(int *arr,size_t length);
              print the array

*/

#include<stdio.h>

void arrprint(int *arr, size_t length);
void arrpop(int *arr, size_t *length);
void arrpush(int *arr, size_t *length, int n);

// Implémentation; compilé uniquemennt si STAIM_IMPLEMENTATION est défini
#ifdef ARRINTM_IMPLEMENTATION

void arrprint(int *arr, size_t length){
    printf("[");
    for (size_t i = 0; i < length ; ++i) 
        (i != (length - 1)) ? printf("%d, ",*(&arr[i])) : printf("%d",*(&arr[i]));
    printf("]\n");
}

void arrpop(int *arr, size_t *length){
    const int n = (*(*(&length))) - 1;
    (*(*(&length))) = (n > 0) ? n : 0;
    (*(&arr[n])) = 0;
}

void arrpush(int *arr, size_t *length, int n){
    (*(&arr[(*(*(&length)))])) = n;
    (*(*(&length))) += 1;
}

void arrinsertAt(int *arr, size_t length, size_t index, int n){
    /*
        O(n/2)
     */
}

#endif

#endif