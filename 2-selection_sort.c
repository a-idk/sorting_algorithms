/* Title: selection_sort.c */
#include "sort.h"

/**
 * selection_sort - function uses selection sort algorithm to sorts
 * an array of integers
 * @array: node of interest
 * @size: size of node elements
 * @a_idk scripting
 *
 * Return: NADA!
 */

void selection_sort(int *array, size_t size)
{
	/* declaring and initializing variables */
	int f = 0;  /* flag */
	int tp;  /* temporary storage */
	int switchs;
	size_t idx1, idx2;  /* index 1 and 2 */

	/* checking for NULL */
	if (array == NULL)
		return;
	/* main loop */
	for (idx1 = 0; idx1 < size; idx1 += 1)
	{
		f = 0, tp = idx1;

		for (idx2 = idx1 + 1; idx2 < size; idx2 += 1)
		{
			if (array[tp] > array[idx2])
				f = f + 1, tp = idx2;
		}
		switchs = array[idx1], array[idx1] = array[tp], array[tp] = switchs;
		/* check for sorted */
		if (f != 0)
			print_array(array, size);
	}
}
