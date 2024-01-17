#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list using Insertion sort
* @list: Pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *key;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		while (key->prev != NULL && key->n < key->prev->n)
		{
			key->prev->next = key->next;
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->next = key->prev;
			key->prev = key->prev->prev;
			key->next->prev = key;

			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;

			print_list(*list);
		}
		current = current->next;
	}
}
