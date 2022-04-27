# Debugger avec Visual Studio Code

Visual Studio Code (VSCode) permet une utilisation frontend du debugger gdb avec des fonctionalités simplifiées qui permettent de faire gagner en productivité.

Toutefois le configurer la première fois peut parfois un peu décourager, surtout si l'on a pas l'habitude des fichiers de configuration json.

Voici les étapes pas à pas pour configurer facilement cet éditeur de texte pour compiler et debugger un programme.

## Fichiers exemples

Voici les fichiers que nous allons utiliser en exemple:

![Fichiers d'exemple](01.png "Fichiers d'exemple")

Ne pas oublier de **compiler avec le flag -g dans une règle du Makefile.** (Penser a compiler toutes le sources avec ce flag, une librairie .a non recompilé ne sera pas repéré dans gdb)

#### main.c
```c
#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

void print_a(char c);
void print_z(char c);

#endif
```

#### function_a.c
```c
#include "header.h"

void print_a(char c)
{
	c = 'a';
	write(1,&c,1);
}

```
#### function_z.c
```c
#include "header.h"

void print_z(char c)
{
	c = 'z';
	write(1,&c,1);
}
```
#### header.h
```c
#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

void print_a(char c);
void print_z(char c);

#endif
```

#### Makefile
Règle minimale pour compiler le programme.
```makefile
debug:
	gcc -g main.c function_a.c function_z.c
```


## Configuration

Maintenant que nous avons un programme qui compile avec une règle Makefile appelée debug, nous avons besoin de nous assurer que VSCode a bien **l'extension C/C++ de Microsoft et l'installer si ce n'est pas le cas.**

![Extension C/C++](02.png "Extension C/C++")

Nous avons ensuite besoin de deux fichiers json (launch.json et tasks.json) dans un dossier caché (.vscode) à la racine de notre projet.

![Fichiers json](03.png "Fichiers json")

C'est ici que nous allons configurer le comportement de VSCode spécifique à notre programme.

#### tasks.json

Nous ajoutons avant tout une tâche dans le fichier *tasks.json* qui est simplement la compilation de notre programme avec la commande *make debug*.

* *label*: le nom de notre tâche qui servira a l'appeler.

```json
{
    "version": "2.0.0",
    "tasks": [
		{
			"label": "compilation",
			"command": "make",
            "args": ["debug"],
			"type": "shell",
			"options": {
                "cwd": "${fileDirname}"
			}
		}
	]
}
```

#### launch.json

Nous ajoutons ensuite la configuration du fichier launch.json pour lancer le debugger, avec l'option *preLaunchTask* appelant notre tâche de compilation au préalable.

```json
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "DEBUG_MY_PROGRAM",
			"type": "cppdbg",
			"preLaunchTask":"compilation",
			"request": "launch",
			"program": "${fileDirname}/a.out",
			"args": [],
			"stopAtEntry": false,
			"cwd": "${fileDirname}",
			"environment": [],
			"externalConsole": false,
			"MIMode": "gdb",
			"setupCommands": [
				{
					"description": "Enable pretty-printing for gdb",
					"text": "-enable-pretty-printing",
					"ignoreFailures": true
				},
				{
					"description":  "Set Disassembly Flavor to Intel",
					"text": "-gdb-set disassembly-flavor intel",
					"ignoreFailures": true
				}
			]
		}

	]
}
```

## Debugger !

Nous avons maintenant configuré VSCode et nous devrions avoir le debugger prêt. Si on le lance et rien ne se passe sans message d'erreur, c'est que tout se passe bien.


![Debugger Ready!](03.png "Debugger Ready!")