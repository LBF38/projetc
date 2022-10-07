# Notes on the project

These are notes for me to reference different sources or thoughts I had on a particular function.

## Function make_cell_from_line

For this function, we use the string.h library.
In this one, we have the function `strtok`

## Function pop

We want to make a function that pops the first element of the list.
On utilise pop pour copier les infos du premier élément vers le paramètre de sortie de la fonction.
On alloue la mémoire de notre paramètre de sortie en dehors de la fonction.
Ensuite, on libère la mémoire de l'élément qui est enlevé après avoir changé la tête de la liste pour le second élément.

## Remarques

Pour faire un checkup des allocations de mémoire et du programme, on utilise `valgrind`
