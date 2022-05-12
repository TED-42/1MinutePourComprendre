# 1 minute pour comprendre ft_memmove(); 
## par Maxime

```c
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int    main(int ac, char **av)
{
    (void)ac;
    char *s1;
    char *s2;

    s1 = calloc(40, sizeof(char));
    s2 = calloc(40, sizeof(char));
    s1 = av[1];
    s2 = av[1] + 3;
    printf("s1 =[%s]\n", s1);
    printf("s2 =[%s]\n", s2);
    for (int i = 0; i < strlen(av[1]); i++)
    {
        s2[i] = s1[i];
        printf("s1[i] =[%c]\n", s2[i]);
        getchar();
    }
    return (0);
}
```

Vous pouvez compiler ce code source depuis chez vous

C'est un exemple assez rudimentaire, voir barbare mais c'est pour éclairer un peu les choses.
Voici le résultat :

```c
s1 = [123456789]
s2 = [456789]
s1[0] = [1]
s1[1] = [2]
s1[2] = [3]
s1[3] = [1]
s1[4] = [2]
s1[5] = [3]
```

**Boucle infinie !**
Mais pourquoi ?
Le souci ici c'est que l'adresse de s1[3] se voit reliée à l'adresse s1[0];
Le signe '=' permet à la fois de changer une valeur mais aussi de voyager entre les pointeurs. 
Dans cet exemple on est redirigé au début.
Si nous avions copié en partant de la fin nous n'aurions pas eu de problème !

```c
for (int i = ft_strlen(av[1]) - 1; i >= 0; i--)
```

La règle est donc simple, si les adresses d'une variable peuvent se chevaucher et que l'on veux la copier, il faut impérativement partir de la fin... 
