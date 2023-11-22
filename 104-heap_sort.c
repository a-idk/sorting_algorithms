/* Title: heap_sort.c */
#include "sort.h"


/**
 * heap_sort - function that uses Heap sort algorithm to sorts an
 * array of integers in ascending order
 * @array: pointer to array
 * @size: size of the pointer
 * @a_idk scripting
 *
 * Return: NADA!
 */

void heap_sort(int *array, size_t size)
{
	size_t index, init = size;
	int sw;

	if (!array)
		return;
	for (index = size / 2; index > 0; index -= 1)
	{
		_swift(array, init, size, index - 1);
	}
	for (index = size; index > 1; index -= 1)
	{
		sw = array[0], array[0] = array[index - 1], array[index - 1] = sw;
		print_array(array, init), _swift(array, init, index - 1, 0);
	}
}


/**
 * _swift - function that checks for swift down
 * @arr: array pointer
 * @size: pointer sizer
 * @init: original size of the array
 * @idx: index as a root of the tree
 *
 * Return: NADA!
 */

void _swift(int *arr, size_t init, size_t size, size_t idx)
{
	/* declaring variable */
	int sw;
	size_t tr1 = idx * 2 + 1;
	size_t tr2 = tr1 + 1;
	int tier1 = arr[tr1];
	int tier2 = arr[tr2];

	if (((tr1 < size) && (tr2 < size) &&
		(tier1 >= tier2 && tier1 > arr[idx])))
		sw = arr[idx], arr[idx] = tier1, arr[tr1] = sw, print_array(arr, init);
	else if ((tr1 == size - 1) && tier1 > arr[idx])
		sw = arr[idx], arr[idx] = tier1, arr[tr1] = sw, print_array(arr, init);
	else if ((tr1 < size) && (tr2 < size) &&
		(tier2 > tier1 && tier2 > arr[idx]))
		sw = arr[idx], arr[idx] = tier2, arr[tr2] = sw, print_array(arr, init);
	if (tr1 < size - 1)
		_swift(arr, init, size, tr1);
	if (tr2 < size - 1)
		_swift(arr, init, size, tr2);
}
