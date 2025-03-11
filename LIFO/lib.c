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

int  depiler(struct Personne **head,struct Personne **last){
    if ((*head) == NULL) return EXIT_SUCCESS;
    if ((*head)->next == NULL) {
        (*head) = NULL;
	(*last) = NULL;
	printf("null head\n");
        return EXIT_SUCCESS;
    }
    struct Personne *temp = (*head)->next;
    struct Personne *templast = (*head);
    if (temp->next == NULL) {
        templast->next = NULL;
	(*last) = templast;
        return EXIT_SUCCESS;
    }
   
    do{
        templast = temp;
        temp = temp->next;
    }while (temp->next != NULL);
    templast->next = NULL;
    (*last) = templast;
    return EXIT_SUCCESS;
}

int enlever(struct Personne **head,int number){
    if ((*head) == NULL) return EXIT_SUCCESS;
    if ((*head)->next == NULL) {
        if ((*head)->number == number) (*head) = NULL;
        return EXIT_SUCCESS;
    }
    if((*head)->number == number) {
        (*head) = (*head)->next;
        return EXIT_SUCCESS;
    }

    struct Personne *current = (*head)->next;
    struct Personne *temp = (*head);

    while(current != NULL){
        if (current->number == number){
            temp->next = current->next;
            return EXIT_SUCCESS;
        }
        temp = current;
        current = current->next;
    }
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
