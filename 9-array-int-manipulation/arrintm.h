#ifndef ARRINTM_H
#define ARRINTM_H

/*
    This is a single header-only-file library that provides easy to manipulate array of int

    To use this library, do this in *one* C file:
        #define ARRINTM_IMPLEMENTATION
        #include "arrintm.h"

    DOCS
        Functions

            arrprint:
              void arrprint(int *arr, size_t length);
                Print the array.
            
            
            arrpop:
              void arrpop(int *arr, size_t length);
                 Removes the final element of the array.
                
                
            arrpush: 
              void arrpush(int *arr, size_t *length, int n);
                Append the integer n to the end of array arr
            
            
            arrinsert: 
              void arrinsert(int *arr, size_t length, size_t i, int k);
                Insert the integer n at index i of the array arr


            arrremove:
              int arrremove(int *arr, size_t *length, size_t index);
              Remove the element at index and return it.
              
*/

#include<stdio.h>

void arrprint(int *arr, size_t length);
void arrpop(int *arr, size_t *length);
void arrpush(int *arr, size_t *length, int k);
void arrinsert(int *arr, size_t *length, size_t i, int k);
int arrremove(int *arr, size_t *length, size_t index);

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

void arrpush(int *arr, size_t *length, int k){
    (*(&arr[*(*(&length))])) = k;
    (*(*(&length))) += 1;
}

void arrinsert(int *arr, size_t *length, size_t i, int k){
    // O(n)
    for (size_t n = (*(*(&length))) - 1; n > i; --n){
        *(&arr[n + 1]) = *(&arr[n]);
    }
    *(&arr[i + 1]) = *(&arr[i]);
    *(&arr[i]) = k;
    (*(*(&length))) += 1;
}

int arrremove(int *arr, size_t *length, size_t index){
    int x = *(&arr[index]);
    for (size_t n = index; n < *(*(&length)) - 1; ++n){
        *(&arr[n]) = *(&arr[n + 1]);
    }
    (*(*(&length))) -= 1;
    return x;
}

#endif

#endif