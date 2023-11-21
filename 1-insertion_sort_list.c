/* Title: insertion_sort_list.c */
#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Double linked list to sort
 * @a_idk scripting
 *
 * Return: NADA!
 */

void insertion_sort_list(listint_t **list)
{
	/* declaring variables */
	listint_t *node;
	listint_t *tnd;  /* temporary node */

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	node = *list;
	while (node != NULL)
	{
		while ((node->next) && ((node->n > node->next->n)))
		{
			tnd = node->next, node->next = tnd->next, tnd->prev = node->prev;
			if (node->prev)
				node->prev->next = tnd;
			if (tnd->next)
				tnd->next->prev = node;
			node->prev = tnd, tnd->next = node;
			if (tnd->prev)
				node = tnd->prev;
			else
				*list = tnd;
			print_list(*list);
		}
		node = node->next;
	}
}
