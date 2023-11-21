/* Title: Shell_sort.c */
#include "sort.h"

/**
 * shell_sort - function that sorts array of integers
 * in ascending order using the Shell sort algorithm
 * @array: array of interest
 * @size: array size
 * @a_idk scripting
 *
 * Return: NADA!
 */

void shell_sort(int *array, size_t size)
{
	/* declaring and initializing variables */
	int sw;  /* temporal storage/switch */
	size_t gp;  /* gap */
	size_t idx1, idx2;

	/* check for only one element */
	if (size < 2)
		return;
	gp = 0;
	/* Knuth sequence loop */
	while (gp <= size / 3)
	{
		gp = gp * 3 + 1;
	}

	while (gp >= 1)
	{
		for (idx1 = gp; idx1 < size; idx1 += 1)
		{
			sw = array[idx1];
			for (idx2 = idx1; idx2 >= gp && array[idx2 - gp] > sw; idx2 -= gp)
				array[idx2] = array[idx2 - gp];
			array[idx2] = sw;
		}
		print_array(array, size);
		gp = gp / 3;
	}
}
