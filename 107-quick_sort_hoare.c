/* Title: quick_sort_hoare.c */

#include "sort.h"

/**
 * hoare_scheme - function that implement hoare partition scheme
 * @arr: the array
 * @start: start of partition
 * @end: end of partition
 * @size: size of array
 * @a_idk scripting
 *
 * Return: start index
 */

int hoare_scheme(int *arr, size_t start, size_t end, size_t size)
{
	/* variables declaration */
	int idx1, idx2;
	int piv;  /* pivot */
	int sw;

	/* initializing the variables */
	piv = arr[end], idx1 = start - 1, idx2 = end + 1;
	while (true)
	{
		do {
			idx1 = idx1 + 1;
		} while (piv > arr[idx1]);
		do {
			idx2 = idx2 - 1;
		} while (piv < arr[idx2]);
		if (idx1 == idx2)
			return (idx2 - 1);
		else if (idx1 > idx2)
			return (idx2);
		sw = arr[idx1], arr[idx1] = arr[idx2], arr[idx2] = sw;
		print_array(arr, size);
	}
}

/**
 * call_hoare - function that calls the hoare func to recursively sorts array
 * @arr: the array
 * @start: start of partition
 * @end: end of partition
 * @size: size of array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void call_hoare(int *arr, size_t start, size_t end, size_t size)
{
	/* variable declaration */
	size_t lim; /* limit */

	if (start < end)
	{
		lim = hoare_scheme(arr, start, end, size);
		call_hoare(arr, start, lim, size), call_hoare(arr, lim + 1, end, size);
	}
}

/**
 * quick_sort_hoare -  function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array
 * @size: size of array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void quick_sort_hoare(int *array, size_t size)
{
	/* check for single element array or NULL */
	if (size < 2 || !array)
		return;
	/* calling the hoare function */
	call_hoare(array, 0, size - 1, size);
}
