#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the full array (for printing)
 * Return: The final index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies Quick sort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array using Quick sort (Lomuto partition)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
