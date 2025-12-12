#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement chaînée d'entiers
 *                       en ordre croissant avec l’algorithme Insertion Sort
 * @list: Pointeur vers le pointeur de tête de la liste
 *
 * Description: On parcourt la liste et insère chaque élément à sa place
 *              correcte dans la portion déjà triée à gauche.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert, *tmp;

    /* Vérifier si la liste est vide ou contient un seul élément */
    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;

    while (current)
    {
        insert = current->prev;
        tmp = current->next;

        /* Tant que l'élément précédent est plus grand, on échange */
        while (insert && current->n < insert->n)
        {
            /* Décrocher current et le placer avant insert */
            insert->next = current->next;
            if (current->next)
                current->next->prev = insert;

            current->prev = insert->prev;
            current->next = insert;

            if (insert->prev)
                insert->prev->next = current;
            else
                *list = current;

            insert->prev = current;

            print_list(*list);

            insert = current->prev;
        }

        current = tmp;
    }
}
