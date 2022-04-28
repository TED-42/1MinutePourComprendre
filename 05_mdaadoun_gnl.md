# 1 minute pour comprendre Get_Next_Line

L'objectif ici est de présenter une approche algorithmique brute en pseudo code pour avoir un angle de vue alternatif sur ce projet.

Cela permettra de comprendre le sujet par croisement de sources tandis que l'implementation rélle en C, le style et l'approche algorithmique fine reste à l'initiative de chacun puisque c'est dans cette recherche que l'apprentissage réel se fait, moins dans un temps trop important passé à essayer de comprendre précisément ce qui est attendu.

## Présentation

Get_Next_Line est une fonctionalité qui permet de découvrir l'ouverture et la lecture d'un fichier (open, read) et aussi l'utilité d'une variable statique (static) qui permet de garder en mémoire une donnée une fois que l'on est sorti d'une fonction.

La fonction get_next_line se prototype ainsi:

```c
char	*get_next_line(int fd);
```

Les points importants:

* Prend un **file descriptor** (fd) qui est simplement un identifiant d'un fichier ouvert. Il est la valeur de retour de la fonction open qui est utilisé à l'exterieur de la fonction get_next_line.

* La valeur renvoyée est une chaine de caractère, la lecture d'une seule ligne par get_next_line, nécessite de surveiller la présence du caractère de retour à la ligne: **'\n'** et de l'ajouter à la fin de la chaîne retournée s'il est présent.

* La fonction get_next_line contient a minima une **variable statique** qui initialise sa valeur à zéro lors de la déclaration (contrairement a une variable simple qui prend une valeur déchet aléatoire dans la mémoire). Cette variable statique contient le résidu qui n'est pas renvoyé par ligne. (Aprés le \n)

* Le concept de fin de fichier (**EOF**) se comprend avec la valeur de retour de la fonction read.

* Le **BUFFER_SIZE** est une variable globale qui est utilisée lors de la lecture du fichier dans le tampon, elle est passée par le compilateur mais peut aussi avoir une valeur par défaut définie dans le header.

## Description

La fonction d'entrée du programme (main) ouvre un fichier (open qui retourne un file descriptor) et appelle get_next_line autant de fois qu'il le souhaite.

La fonction get_next_line réalise ensuite ces étapes:  

1. Prépare une variable **tampon**, une variable *statique* **sauvegarde**, une variable **ligne** qui sera retourné (donc une chaîne char *)...  
2. Commence par vérifier s'il y a un reste dans **sauvegarde** et l'ajoute à **ligne**. Si la sauvegarde est vide, étape 3.  
	* Si la ligne est complète (présence de \n), alors la sauvegarde est mise a jour et la ligne est retournée. Sinon, étape 3.  
3. Lecture du fichier grâce au file descriptor et au **tampon** qui a la taille du **BUFFER_SIZE**. Le contenu du tampon est ajouté à **ligne** jusqu'à trouver un saut de ligne '\n' ou d'arriver à la fin du fichier.
	* Si la lecture n'a plus rien à lire ou si il y'a un problème (mauvais file descriptor...) on retourne **ligne** ou **NULL** selon le cas.
4. Finalement, ajoute le résidu du **tampon** (bytes aprés le premier \n non ajouté à ligne) dans sauvegarde avant de retourner **ligne**

## Bye

Voilà, ce n'est certainement pas la seule ni la meilleure approche, mais cette description est un exemple pour comprendre ce qui est attendu avec GNL, un exemple est intéressant à croiser avec d'autres exemples pour comprendre plus profondement le sujet, bon courage pour votre implémentation personnelle.
