/* Title: counting_sort.c */
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: the array
 * @size: array size
 * @a_idk scripting
 *
 * Return: NADA!
 */

void counting_sort(int *array, size_t size)
{
	/* variable declaration */
	size_t idx1;
	int idx2, max; 
	int *array_num, *array_tmp;

	/* check for array validity and more than 1 element */
	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (idx1 = 0; idx1 < size; idx1 = idx1 + 1)
	{
		if (array[idx1] > max)
			max = array[idx1];
	}

	/* memory allocation */
	array_num = calloc((max + 1), sizeof(int));
	for (idx1 = 0; idx1 < size; idx1 = idx1 + 1)
		array_num[array[idx1]] += 1;
	for (idx2 = 1; idx2 < max; idx2 = idx2 + 1)
		array_num[idx2 + 1] = array_num[idx2 + 1] + array_num[idx2];
	print_array(array_num, max + 1);

	/* allocating dynamic memory */
	array_tmp = malloc(size * sizeof(int));
	for (idx1 = 0; idx1 < size; idx1 = idx1 + 1)
	{
		array_num[array[idx1]] = array_num[array[idx1]] - 1;
		array_tmp[array_num[array[idx1]]] = array[idx1];
	}
	for (idx1 = 0; idx1 < size; idx1 = idx1 + 1)
		array[idx1] = array_tmp[idx1];

	/* freeing memory */
	free(array_tmp), free(array_num);
}
