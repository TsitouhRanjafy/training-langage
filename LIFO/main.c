#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


struct Personne {
    int number;
    struct Personne *next;
};

int main(){

    struct Personne *head = NULL;
    struct Personne *last = NULL;
    int inputNumber,count;

    // Emplier
    count = 0;
    inputNumber = 0;
    while (inputNumber >= 0){
        struct Personne *new = malloc(sizeof(struct Personne));
        if (new == NULL){
            exit(EXIT_FAILURE);
        }
        scanf("%d",&inputNumber);
        new->number = inputNumber;
        new->next = NULL;

        if (count == 0){
            head = new;
            last = head;
        } else {
            last->next = new; // = (*last).next = new
            last = new;
        }
        ++count;
    }

    printf("\n\n");
    struct Personne *current;
    current = head;
    printf("%d -> ",current->number);
    do{
        current = current->next;
        printf("%d -> ",current->number);
    } while (current->next != NULL);

  
    return EXIT_SUCCESS;
}

