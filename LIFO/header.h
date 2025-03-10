#ifndef HEADER_H
#define HEADER_H

struct Personne {
    int number;
    struct Personne *next;
};
void empiler(struct Personne **head,struct Personne **last,int number);
void depiler(struct Personne **head);
void afficher(struct Personne **head);

#endif