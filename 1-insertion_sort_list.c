#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Double pointer to the head of the list
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        while (temp->prev && temp->prev->n > temp->n)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            temp->next->prev = temp;

            print_list(*list);
        }
        current = current->next;
    }
}
