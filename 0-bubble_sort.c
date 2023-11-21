/* Title: 0-bubble_sort.c */
#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using bubble sort algorithm
 * @array: integer array
 * @size: size of the array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void bubble_sort(int *array, size_t size)
{
	/* declaring and initializing variables */
	size_t index1;
	size_t index2;
	size_t temp = 0;

	/* checking for single element or empty array */
	if (size < 2)
		return;
	/* main loop */
	for (index1 = 0; index1 < size; index1 += 1)

		for (index2 = 0; index2 < size; index2 += 1)
		{
			if (array[index2 + 1] && (array[index2] > array[index2 + 1]))
			{
				temp = array[index2], array[index2] = array[index2 + 1];
				array[index2 + 1] = temp, print_array(array, size);
			}
		}
}
