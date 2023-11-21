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
	size_t x;
	int check;
	size_t sw = 0;

	/* checking for single element or empty array */
	if (size < 2)
		return;
	if (!array || size == 0)
        return;
	check = 0;
	/* main loop */
	while (check == 0)
	{
		check = 1;
		for (x = 0; x < size - 1; x += 1)
		{
			if (array[x + 1] < array[x])
			{
				check = 0;
				sw = array[x], array[x] = array[x + 1], array[x + 1] = sw;
				print_array(array, size);
			}
		}
	}
}
