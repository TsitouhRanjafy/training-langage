# RPG character class hierarchy design

Considérons un mini jeu de rôle ou il y a différents types de personnage :
un Roi, un Soldat, un Sorcier et un prêtre.

Chaque personnage obligatoirement possède 3 caractéristiques principales
qui sont : Déplacement, Attaque, Soin.

Mais chaque attribut diffère selon le personnage comme nous montre les
données suivantes :

- Roi :     
    - Déplacement : Marcher
    - Attaque : Pas d’attaque
    - Soin : Pas de soin
- Soldat :          
    - Déplacement : Courir
    - Attaque : Fusil
    - Soin : Soin de base
- Sorcier :         
    - Déplacement : Voler
    - Attaque : Avec un sort
    - Soin : Soin de base
- Prêtre :      
    - Déplacement : Marcher
    - Attaque : Pas d’attaque
    - Soin : Super soin

Implémentez ce problème en optimisant votre code.

Pour faciliter votre développement, utilisez juste un Console.WriteLine pour
représenter les différents attributs.

```csharp
Public void SeDeplacer () {
    Console.WriteLine (“Je Marche”);
}
```
Considérez ces points pour essayer d’optimisez votre structure :

- Les personnages ont obligatoirement les 3 attributs principaux mais seule
    leur façon de procéder sont différente.
- Il y a certaines redondances sur les caractéristiques de certain
    personnage. Par exemple, le Roi et le Prêtre se déplace de la même façon
    et n’ont pas d’attaque. Donc prenez en compte que dans notre exercice,
    c’est facile d’écrire Console.WriteLine (“Je Marche”) dans la classe Roi et
    Prêtre. Mais avec un algorithme de déplacement complexe, la
    maintenance devient plus difficile avec des blocs codes redondants.


