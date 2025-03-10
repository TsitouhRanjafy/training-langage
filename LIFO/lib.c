#include<stdio.h>
#include<stdlib.h>

struct Personne {
    int number;
    struct Personne *next;
};

void empiler(struct Personne **head,struct Personne **last,int number){
    struct Personne *new = malloc(sizeof(struct Personne));
    if (new == NULL) exit(EXIT_FAILURE);
    new->number = number;
    new->next = NULL;

    if (*head == NULL){
        *head = new;
        *last = *head;
    } else {
        (*last)->next = new;
        (*last) = new;
    }
}

int  depiler(struct Personne **head){
    if ((*head) == NULL) return EXIT_SUCCESS;
    if ((*head)->next == NULL) {
        (*head) = NULL;
        return EXIT_SUCCESS;
    }
    struct Personne *temp = (*head)->next;
    struct Personne *last = (*head);
    if (temp->next == NULL) {
        last->next = NULL;
        return EXIT_SUCCESS;
    }
   
    do{
        last = temp;
        temp = temp->next;
    }while (temp->next != NULL);
    last->next = NULL;
    return EXIT_SUCCESS;
}

void afficher(struct Personne **head){
    struct Personne *current;
    current = (*head);
    if (current == NULL) return;
    printf("%d - > ",current->number);

    if (current->next == NULL) return;
    do{
        current = current->next;
        printf("%d -> ",current->number);
    } while (current->next != NULL);
}