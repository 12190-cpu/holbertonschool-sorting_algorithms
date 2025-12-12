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

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
