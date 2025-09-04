/* intdicokv.h v0.1 - dictionary of int

    This is a single header-only-file library that provides to use a dico type int

    To use this library, do this in *one* C file:
        #include "intdicokv.h"

    The dico declaration
        DICO_KV foo = {0};

    DOCS
        Functions

        set:
            void set(DICO_KV *dico_kv, int k, int v);
                set a <key, value>

        getValue:
            int getValue(DICO_KV *dico_kv, int k);
                get a value of <key>
                return UNDEFINED (equal INT_MAX) if not defined

        getKey:
            int getKey(DICO_KV *dico_kv, int v);
                get a key of a <value>
                return UNDEFINED (equal INT_MAX) if not defined

        del:
            bool del(DICO_KV *dico_kv, int k);
                delete a <key,value>
                return true (equal 1) on success, else false(0)
                
        dfree:
            void dfree(DICO_KV *dico_kv);
                free the dico


*/

#ifndef INTDICOKV_H
#define INTDICOKV_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

#define INTDICOKV_INITIAL_CAPACITY 64
#define UNDEFINED INT_MAX

typedef struct {
    int key;
    int value;
    int used; // 0 = empty, 1 = filled
} hm_pair_int;

typedef struct {
    hm_pair_int *IN;
    hm_pair_int *OUT;
} DICO_KV;



// Macros
#define hmput(tbl, key, val) stbds_hmput(&(tbl), key, val)
#define hmget(tbl, key)      stbds_hmget(tbl, key)
#define hmdel(tbl, key)      stbds_hmdel(&(tbl), key)
#define hmfree(tbl)          stbds_hmfree(tbl)

// Simple hash function for int
static uint32_t stbds_int_hash(int key) {
    key ^= (key >> 17);
    key *= 0xed5ad4bb;
    key ^= (key >> 11);
    key *= 0xac4c1b51;
    key ^= (key >> 15);
    key *= 0x31848bab;
    key ^= (key >> 14);
    return (uint32_t)key;
}

// Insert or update
static void stbds_hmput(hm_pair_int **table, int key, int val) {
    if (!*table) {
        *table = calloc(INTDICOKV_INITIAL_CAPACITY, sizeof(hm_pair_int));
    }

    uint32_t hash = stbds_int_hash(key);
    for (size_t i = 0; i < INTDICOKV_INITIAL_CAPACITY; ++i) {
        size_t index = (hash + i) % INTDICOKV_INITIAL_CAPACITY;
        if (!(*table)[index].used || (*table)[index].key == key) {
            (*table)[index].key = key;
            (*table)[index].value = val;
            (*table)[index].used = 1;
            return;
        }
    }
}

// Retrieve pointer to value
static int *stbds_hmget(hm_pair_int *table, int key) {
    if (!table) return NULL;

    uint32_t hash = stbds_int_hash(key);
    for (size_t i = 0; i < INTDICOKV_INITIAL_CAPACITY; ++i) {
        size_t index = (hash + i) % INTDICOKV_INITIAL_CAPACITY;
        if (table[index].used && table[index].key == key)
            return &table[index].value;
    }
    return NULL;
}

// Delete key
static void stbds_hmdel(hm_pair_int **table, int key) {
    if (!*table) return;

    uint32_t hash = stbds_int_hash(key);
    for (size_t i = 0; i < INTDICOKV_INITIAL_CAPACITY; ++i) {
        size_t index = (hash + i) % INTDICOKV_INITIAL_CAPACITY;
        if ((*table)[index].used && (*table)[index].key == key) {
            (*table)[index].used = 0;
            return;
        }
    }
}

// Free hashmap
static void stbds_hmfree(hm_pair_int *table) {
    if (table) free(table);
}

void set(DICO_KV *dico_kv, int k, int v){
    assert(k < UNDEFINED && k < UNDEFINED);
    int *a = hmget(dico_kv->IN,k);
    if (a != NULL) hmdel(dico_kv->OUT,(*a));
    hmput(dico_kv->IN,k,v);
    hmput(dico_kv->OUT,v,k);
}

bool del(DICO_KV *dico_kv, int k){
    int *v = hmget(dico_kv->IN,k); 
    if (v == NULL) return false;
    hmdel(dico_kv->IN,k);
    hmdel(dico_kv->OUT,(*v));
    return true;
}

int getValue(DICO_KV *dico_kv, int k){
    int *v = hmget(dico_kv->IN,k);
    return (v != NULL) ? (*v) : UNDEFINED;
}

int getKey(DICO_KV *dico_kv, int v){
    int *k = hmget(dico_kv->OUT,v);
    return (k != NULL) ? (*k) : UNDEFINED;
}

void dfree(DICO_KV *dico_kv){
    hmfree(dico_kv->IN);
    hmfree(dico_kv->OUT);
}

#endif // STB_DS_INTMAP_H
