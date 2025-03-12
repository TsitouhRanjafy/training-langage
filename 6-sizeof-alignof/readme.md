# Alignement en memoire

```C
#include <stddef.h>
#include <stdio.h>

struct exemple{
    double flottant;
    char lettre;
    unsigned int entier;
};


int main(void)
{
    printf("struct exemple : %zu\n", sizeof(struct exemple));
    return 0;
}
```

> struct exemple : 16       


**Pourquoi 16, mais pas 13?**

En fait, il faut savoir qu’il n’est dans les faits pas possible de lire ou modifier un multiplet spécifique de la mémoire vive. Techniquement, il est uniquement possible de lire ou écrire des blocs de données de taille fixe appelés mots mémoire. Dès lors, il est nécessaire que les données à lire ou à écrire soient contenues dans un de ces mots mémoires.

Quel rapport avec notre structure me direz-vous ? Supposons que notre RAM utilise des blocs de huit octets. Si notre structure faisait treize octets, voici comment elle serait vue en termes de blocs.



        +---------+----------+
        | Adresse |  Champ   |
    +-> +---------+----------+
    |   |    0    |          |
    |   +---------+          |
    |   |    1    |          |
    |   +---------+          |
    |   |    2    |          |
    |   +---------+          |
    |   |    3    |          |
    |   +---------+ flottant |
    |   |    4    |          |
    |   +---------+          |
    |   |    5    |          |
    |   +---------+          |
    |   |    6    |          |
    |   +---------+          |
    |   |    7    |          |
    +-> +---------+----------+
    |   |    8    | lettre   |
    |   +---------+----------+
    |   |    9    |          |
    |   +---------+          |
    |   |    10   |          |
    |   +---------+ entier   |
    |   |    11   |          |
    |   +---------+          |
    |   |    12   |          |
    |   +---------+----------+
    |
    |
    |
    .
    .
    .


Comme vous le voyez, le champ flottant remplit complètement le premier mot, alors que les champs lettre et entier ne remplissent que partiellement le second. Dans le seul cas de notre structure, cela ne pose pas de problème, sauf que celle-ci n’est pas seule en mémoire. En effet, imaginons maintenant qu’un autre int suive cette structure, nous obtiendrions alors ceci.

        +---------+----------+
        | Adresse |  Champ   |
    +-> +---------+----------+
    |   |    0    |          |
    |   +---------+          |
    |   |    1    |          |
    |   +---------+          |
    |   |    2    |          |
    |   +---------+          |
    |   |    3    |          |
    |   +---------+ flottant |
    |   |    4    |          |
    |   +---------+          |
    |   |    5    |          |
    |   +---------+          |
    |   |    6    |          |
    |   +---------+          |
    |   |    7    |          |
    +-> +---------+----------+
    |   |    8    | lettre   |
    |   +---------+----------+
    |   |    9    |          |
    |   +---------+          |
    |   |    10   |          |
    |   +---------+ entier   |
    |   |    11   |          |
    |   +---------+          |
    |   |    12   |          |
    |   +---------+----------+
    |   |    13   |          |
    |   +---------+          |
    |   |    14   |          |
    |   +---------+ int      |
    |   |    15   |          |
    +-> +---------+          |
    |   |    16   |          |
    |   +---------+----------+
    |
    |
    |
    .
    .
    .

Et là, c’est le drame, le second entier est à cheval sur le deuxième et le troisième mot. Pour éviter ces problèmes, les compilateurs ajoutent des multiplets dit « de bourrage » (padding en anglais), afin que les données ne soient jamais à cheval sur plusieurs mots. Dans le cas de notre structure, le compilateur a ajouté trois octets de bourrage juste après le membre lettre afin que les deux derniers champs occupent un mot complet.


        +---------+----------+
        | Adresse |  Champ   |
    +-> +---------+----------+
    |   |    0    |          |
    |   +---------+          |
    |   |    1    |          |
    |   +---------+          |
    |   |    2    |          |
    |   +---------+          |
    |   |    3    |          |
    |   +---------+ flottant |
    |   |    4    |          |
    |   +---------+          |
    |   |    5    |          |
    |   +---------+          |
    |   |    6    |          |
    |   +---------+          |
    |   |    7    |          |
    +-> +---------+----------+
    |   |    8    | lettre   |
    |   +---------+----------+
    |   |    9    |          |
    |   +---------+          |
    |   |    10   | bourrage |
    |   +---------+          |
    |   |    11   |          |
    |   +---------+----------+
    |   |    12   |          |
    |   +---------+          |
    |   |    13   |          |
    |   +---------+ entier   |
    |   |    14   |          |
    |   +---------+          |
    |   |    15   |          |
    +-> +---------+----------+
    |   |    16   |          |
    |   +---------+          |
    |   |    17   |          |
    |   +---------+ int      |
    |   |    18   |          |
    |   +---------+          |
    |   |    19   |          |
    |   +---------+----------+
    |
    |
    |
    .
    .
    .

# L’opérateur _Alignof

Il est possible de connaître les contraintes d’alignement d’un type, à l’aide de l’opérateur `_Alignof` (ou alignof si l’en-tête `<stdalign.h>` est inclus). Ce dernier s’utilise de la même manière que l’opérateur `sizeof`, si ce n’est que seul un type peut lui être fourni et non une expression. Le résultat de l’opérateur est, comme pour `sizeof`, une expression de type `size_t`.

Le code suivant vous donne les contraintes d’alignement pour chaque type de base.
```C

#include <stdalign.h>
#include <stdio.h>


int main(void){
    printf("_Bool: %zu\n", _Alignof(_Bool));
    printf("char: %zu\n", _Alignof(char));
    printf("short: %zu\n", _Alignof(short));
    printf("int : %zu\n", _Alignof(int));
    printf("long : %zu\n", _Alignof(long));
    printf("long long : %zu\n", _Alignof(long long));
    printf("float : %zu\n", alignof(float));
    printf("double : %zu\n", alignof(double));
    printf("long double : %zu\n", alignof(long double));
    return 0;
}
```

Résultat

    _Bool: 1
    char: 1
    short: 2
    int : 4
    long : 8
    long long : 8
    float : 4
    double : 8
    long double : 16