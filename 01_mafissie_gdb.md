# 1 minute pour comprendre GDB 
## par Maxime

GDB c'est un peu rentrer dans la salle de l'esprit et du temps dans Dragon Ball Z :
Le temps pour trouver un souci technique est divisé par 5, voir plus !
Cet outil demande parfois un peu de patience mais permet une compréhension parfaite de son code.

Voici donc la recette !  Et autant prendre un petit exemple sur un code qui segfault !

```c
1 #include <unistd.h>
2 #include <stdio.h>
3
4 int main(void)
5 {
6        void *str = NULL;
7
8        while (1)
9            printf("%s\n", str++);
10       return (0);
11 }
```

1. Compiler avec le flag *-g* 
```
gcc -g main.c
```
2. Executer avec *gdb nom_du_programme*
```
gdb a.out
```
Voila, vous y êtes déjà !
Sauf que le programme est déjà terminé, il va falloir le stopper pour la prochaine exécution...

Liste des commandes de bases :
* **list**  => pour visionner les lignes de codes (rajouter un numéro, pour préciser la ligne que vous voulez)
* **breakpoint** [nbr] => permet de stopper le code à une ligne voulue
* **run** [args] => permet de lancer le programme, vous pouvez rajouter des arguments si vous avez un main avec un argv
Une fois le programme lancé et vos breakpoint mis en place :
* **next** => pour passer a la ligne suivante
* **print** => ce que vous voulez, ça peut être une variable ou carrément le résultat d'une fonction entière

Pour cet exemple plus haut, une simple run aurait permis de régler le problème, car GDB vous dit où se trouve la ligne précisément d'un segfault
Vous pouvez rajouter un -g dans votre Makefile, ça marche très bien.

Il y a bien entendu plus de possibilités, mais je vous laisserai le plaisir de la découverte :
* Changer la valeur d'une variable
* Injecter une nouvelle variable en pleine compilation
* Suivre l'état d'une variable quand elle est changée
* Connaitre la variable à laquelle appartient telle adresse
* etc...
