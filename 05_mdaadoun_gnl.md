# 1 minute pour comprendre Get Next Line

L'objectif ici est de présenter une approche algorithmique basique en pseudo code pour avoir un angle de vue sur la résolution de ce projet.  

Cela permettra de comprendre d'une autre façon le sujet, l'implementation rélle en C, le style et l'approche de ses algorithmes personnels reste à l'initiative de chacun puisque c'est dans cette recherche que l'apprentissage réel se fait. 

## Présentation

Get Next Line est une fonctionalité qui permet de découvrir l'ouverture et la lecture d'un fichier (open, read) et aussi l'utilité d'une variable statique (static) qui permet de garder en mémoire une donnée une fois que l'on est sorti d'une fonction.

La fonction get_next_line se prototype ainsi:

```c
char	*get_next_line(int fd);
```

Les points importants:

* Prend un **file descriptor** (fd) qui est simplement un identifiant d'un fichier ouvert. Il est la valeur de retour de la fonction open qui est utilisé à l'exterieur de la fonction get_next_line.

* La valeur renvoyé est une chaine de caractère, la lecture d'une seule ligne par get_nex_line, necessite de surveiller la présence du caractére de retour à la ligne: **'\n'** et de l'ajouter à la fin de la chaîne retournée s'il est présent.

* La fonction get_next_line contient a minima une variable statique qui initialise sa valeur à zéro lors de la déclaration (contrairement a une variable simple qui prend une valeur déchet aléatoire dans la mémoire). Cette variable statique contient le résidu qui n'est pas renvoyé par ligne. (Aprés le \n)

* Le concept de fin de fichier (EOF) se comprend avec la valeur de retour de la fonction read.

## Description

Comportement général du programme en pseudo code pour comprendre globalement ce qui est attendu de ce projet.

La fonction d'entrée du programme (main) ouvre un fichier (open qui retourne un file descriptor) et appel get_next_line.

La fonction get_nex_line réalise ensuite ces étapes:  

1. Prépare une variable **tampon**, une variable *statique* **sauvegarde**, une variable **ligne** qui sera retourné (donc une chaîne char *)...  
2. Commence par vérifier s'il y a un reste dans **sauvegarde** et l'ajoute à **ligne**. Si la sauvegarde est vide, étape 3.  
	* Si la ligne est complète (présence de \n), alors la sauvegarde est mise a jour et la ligne est retournée. Sinon, étape 3.  
3. Lecture du fichier grâce au file descriptor et au **tampon**. Le contenu du tampon est ajouté à **ligne** jusqu'à trouver un saut de ligne '\n' ou d'arriver à la fin du fichier.
	* Si la lecture n'a plus rien à lire ou si il y'a un problème (mauvais file descriptor...) on retourne **ligne** ou **NULL** selon le cas.
4. Finalement, ajoute le residu du **tampon** (bytes aprés le premier \n non ajouté à ligne) dans sauvegarde avant de retourner **ligne**

Voilà, ce n'est certainement pas la seule ni la meilleure approche, mais cette description est un exemple pour comprendre ce qui est attendu avec GNL, un exemple est interessant à croiser avec d'autres exemples, bon courage pour votre implementation personnelle.