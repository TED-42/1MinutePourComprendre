# 1 minute pour comprendre Malloc/free/Valgrind 
## par Maxime

**Lorsque nous stockons de la mémoire pour ensuite la manipuler nous avons deux cas de figure :**

### 1. Nous savons d'avance avec qui nous avons rendez-vous :
```c
char *client = "Bob"; //
```

### 2️. Nous ne savons pas avec qui...
```c
void *client; // ??? 
```

Dans le cas **2** nous ne savons pas encore le prénom de notre client !

Il y a donc des regles lorsque nous demandons à l'ordinateur de nous allouer de la mémoire (malloc) :

**Il a besoin du type (int, char,...) et de la taille.**

Il faut ensuite prendre en considération cette contrainte :

**L'ordinateur ne sais pas quand le client partira (ne devra plus etre enregistré)**

*Il faudra donc lui dire, free*

Ainsi :

```c
void *client;
client = (char *)malloc(sizoef(char) * 4); // C'est un bob qui apparait
ft_strlcpy(client, "Bob", 4);

free(client); // Le rendez-vous est fini
```

### Valgrind

Lexique :
* **malloc** = Allouer de la mémoire
* **free** = libérer de la mémoire

Les cas d'erreurs du au malloc/free :

1. Malloc sur un malloc
2. Free sur un free
3. Ne pas free un malloc
4. Ecrire de la mémoire en dehors d'un malloc
5. Lire de la mémoire en dehors d'un malloc

```c
    char *str;
    str = calloc(sizeof(char), 2);
    if (str[5])
// Invalide Read
    str[5] = 'N';
// Invalide Write 
    str = calloc(sizeof(char), 2);
// Memory leaks
    free(str);
    free(str);
// Double free
    char *str = malloc(5);
    str[0] = '1';
    return (str);
// Not '\0' memory unitialised is bad
    return (0);
```
Ça devrait vous éclairer ! 
