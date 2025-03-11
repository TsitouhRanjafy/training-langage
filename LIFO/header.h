#ifndef HEADER_H
#define HEADER_H

struct Personne {
    int number;
    struct Personne *next;
};
void empiler(struct Personne **head,struct Personne **last,int number);
void depiler(struct Personne **head,struct Personne **last);
void afficher(struct Personne **head);
int enlever(struct Personne **head,int number);
int inserer(struct Personne **head,int position,int number);

#endif
