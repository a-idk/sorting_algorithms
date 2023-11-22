/* Title: radix_sort.c */
#include "sort.h"

/**
 * maxVal - function that gets max value of array
 * @array: the array
 * @size: array size
 * @a_idk scripting
 *
 * Return: max value
 */

int maxVal(int *array, int size)
{
	/* declaring variable */
	int index;
	int xval;

	xval = array[0];
	for (index = 1; index < size; index += 1)
	{
		if (array[index] > xval)
			xval = array[index];
	}
	return (xval);
}

/**
 * sorting - function that count sort
 * @array: the array
 * @ex: exponential
 * @size: array size
 * @temp: array to save the temporary values
 * @a_idk scripting
 *
 * Return: NADA!
 */

void sorting(int *array, size_t size, int ex, int *temp)
{
	/* declaring variable */
	int index;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (index = 0; index < (int)size; index += 1)
		count[(array[index] / ex) % 10] += 1;
	/* switch count */
	for (index = 1; index < 10; index += 1)
		count[index] += count[index - 1];
	/* Build the temp array */
	for (index = size - 1; index >= 0; index -= 1)
	{
		temp[count[(array[index] / ex) % 10] - 1] = array[index];
		count[(array[index] / ex) % 10]--;
	}
	for (index = 0; index < (int)size; index += 1)
		array[index] = temp[index];
}

/**
 * radix_sort - function that uses radix sort algorithm to sort an array
 * @array: array
 * @size: size of the array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void radix_sort(int *array, size_t size)
{
	/* declaring variables */
	int x, max, *sorted_array;

	max = 0;
	sorted_array = NULL;
	/* checking for NUll and 1 element */
	if (array == NULL || size < 2)
		return;
	max = maxVal(array, size), sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
		return;
	for (x = 1; max / x > 0; x *= 10)
		sorting(array, size, x, sorted_array), print_array(array, size);
	free(sorted_array);
}
