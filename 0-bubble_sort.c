#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'entiers en ordre croissant
 *               en utilisant l'algorithme de Bubble sort
 * @array: Le tableau à trier
 * @size: La taille du tableau
 *
 * Description: On compare chaque élément avec le suivant et on échange
 *              si nécessaire, puis on répète jusqu'à ce que le tableau
 *              soit trié. On affiche le tableau après chaque échange.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	/* Si le tableau est vide ou contient moins de 2 éléments, ne rien faire */
	if (!array || size < 2)
		return;

	/* Boucle pour chaque élément du tableau */
	for (i = 0; i < size - 1; i++)
	{
		/* Boucle pour comparer chaque paire d'éléments adjacents */
		for (j = 0; j < size - i - 1; j++)
		{
			/* Si l'élément courant est plus grand que le suivant, on échange */
			if (array[j] > array[j + 1])
			{
				temp = array[j];        /* Sauvegarder la valeur courante */
array[j] = array[j + 1];/* Remplacer par l'élément suivant */
				array[j + 1] = temp;    /* Placer l'élément courant à la position suivante */

				/* Afficher le tableau après chaque échange */
				print_array(array, size);
			}
		}
	}
}
