#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


struct personne {
    int numero;
    struct personne *next;
};

int main(){

    struct personne *head = NULL;
    struct personne *last = NULL;
    int n,cpt;

    // Emplier
    cpt = 0;
    n = 0;
    while (n >= 0){
        struct personne *nouveau = malloc(sizeof(struct personne));
        if (nouveau == NULL){
            exit(EXIT_FAILURE);
        }
        scanf("%d",&n);
        nouveau->numero = n;
        nouveau->next = NULL;

        if (cpt == 0){
            head = nouveau;
            last = head;
        } else {
            last->next = nouveau; // = (*last).next = nouveau
            last = nouveau;
        }
        ++cpt;
    }

    printf("\n\n");
    struct personne *current;
    current = head;
    printf("%d -> ",current->numero);
    do{
        current = current->next;
        printf("%d -> ",current->numero);
    } while (current->next != NULL);

  
    return EXIT_SUCCESS;
}

