/* Title: cocktail_sort_list.c */
#include "sort.h"

/**
 * swapping2 - function that swaps doubly linked list nodes
 * @nd: node base to change
 * @lst: list head
 * @_idk scripting
 *
 * Return: NADA!
 */

void swapping2(listint_t **nd, listint_t **lst)
{
	/* declaring variables */
	listint_t *nxt_nd;  /* next node */
	listint_t *temp_ptr;  /* temporary node pointer*/
	listint_t *nd_ptr = *nd;

	/* checking for head */
	if (!(*nd)->prev)
		*lst = (*nd)->next;
	/* updating the nodes */
	nd_ptr = temp_ptr = *nd, nxt_nd = nd_ptr->next;
	nd_ptr->next = nxt_nd->next, temp_ptr = nd_ptr->prev;
	nd_ptr->prev = nxt_nd, nxt_nd->next = nd_ptr, nxt_nd->prev = temp_ptr;
	if (nxt_nd->prev)
		nxt_nd->prev->next = nxt_nd;
	if (nd_ptr->next)
		nd_ptr->next->prev = nd_ptr;
	*nd = nxt_nd;
}

/**
 * cocktail_sort_list - function that sorts doubly linkedlist of ints
 * ascending order using the Cocktail shaker algorithm
 * @list: list head
 * @a_idk scripting
 *
 * Return: NADA!
 */

void cocktail_sort_list(listint_t **list)
{
	/* declaring and intializing variables */
	int count;
	int start;
	int end;
	listint_t *hd;
	listint_t *tmp;

	count = 0, start = -1, end = -1;
	/* checking for list validity */
	if (!list || !(*list))
		return;
	if (!((*list)->prev) && !((*list)->next))
		return;

	hd = *list;
	while (end >= start)
	{
		start = start + 1;
		while (hd->next && count != end)
		{
			if (hd->n > hd->next->n)
				tmp = hd, swapping2(&tmp, list), print_list(*list), hd = tmp;
			count = count + 1, hd = hd->next;
		}
		if (start == 0)
			end = count;
		end = end - 1;
		while (hd->prev && count >= start)
		{
			if (hd->n < hd->prev->n)
			{
				tmp = hd->prev, swapping2(&tmp, list);
				print_list(*list), hd = tmp->next;
			}
			count = count - 1, hd = hd->prev;
		}
	}
}
