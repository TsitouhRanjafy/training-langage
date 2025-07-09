#include "intdicokv.h"
#include<stdio.h>

int main() {
    DICO_KV dico = {0};

    set(&dico,2,2024);
    set(&dico,2,2025);
    printf("%d => (%d)",getKey(&dico,2025),getValue(&dico,2));

    
    if (getKey(&dico,2027) == UNDEFINED){
        printf("\n the value 2027 not in the dico");
    }
    dfree(&dico);
    return 0;
}
