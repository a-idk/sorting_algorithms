/* Title: quick_sort.c */
#include "sort.h"

/**
 * swapping - function that xchanges 2 elements position in an array
 * @array: array of interest
 * @before: The index of the left item
 * @after: The index of the right item
 * @a_idk scripting
 *
 * Return: NADA!
 */

void swapping(int *array, size_t before, size_t after)
{
	/* declaring variable */
	int st;  /* temporal store */

	if (array != NULL)
		st = array[before], array[before] = array[after], array[after] = st;
}

/**
 * lomuto_part - function that implements lomuto partition scheme and the
 * quick sorts algorithm to implement sorting
 * @array: array
 * @start: initial point of sub-array.
 * @end: last point of sub-array.
 * @size: The length of the array.
 * @a_idk scripting
 *
 * Return: NADA!
 */

void lomuto_part(int *array, size_t start, size_t end, size_t size)
{
	/* declaring variables */
	int piv;  /* pivot */
	size_t rt;  /* right */
	size_t lt;  /* left */

	if ((start >= end) || (array == NULL))
		return;
	piv = array[end], rt = start;
	for (lt = start; lt < end; lt += 1)
	{
		if (array[lt] <= piv)
		{
			if (rt != lt)
				swapping(array, rt, lt), print_array(array, size);
			rt = rt + 1;
		}
	}
	if (rt != end)
		swapping(array, rt, end), print_array(array, size);
	if (rt - start > 1)
		lomuto_part(array, start, rt - 1, size);
	if (end - rt > 1)
		lomuto_part(array, rt + 1, end, size);
}

/**
 * quick_sort - main function that sorts the array of elements
 * using the quick sort algorithm & Lomuto's partition scheme
 * @array: array of interest
 * @size: size of array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void quick_sort(int *array, size_t size)
{
	if (array)
		lomuto_part(array, 0, size - 1, size);
}
