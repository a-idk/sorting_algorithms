/* Title: Bitonic_sort.c */
#include "sort.h"

/**
 * bit_recurse - function that recursively sorts bitonic sequences
 * in both orders
 * @ar: the array
 * @first: the first element
 * @elem: number of elements
 * @order: ascending order and descending order (1 and 0)
 * @a_idk scripting
 *
 * Return: NADA!
 */

void bit_recurse(int ar[], int first, int elem, int order)
{
	int ctr;
	int idx;
	int sw;

	if (elem > 1)
	{
		ctr = elem / 2; /* mid number in the elements list/array */
		for (idx = first; first + ctr > idx; idx += 1)
		{
			if ((order == 1 && ar[idx] > ar[idx + ctr])
					|| (order == 0 && ar[idx] < ar[idx + ctr]))
			{
				sw = ar[idx], ar[idx] = ar[idx + ctr], ar[idx + ctr] = sw;
			}
		}
		bit_recurse(ar, first, ctr, order);
		bit_recurse(ar, ctr + first, ctr, order);
	}
}


/**
 * bit_imp - function that implements bitonic sort algorithm
 * @ar: the array
 * @first: the first element
 * @n: number of elements
 * @sz: array size
 * @order: ascending order and descending order (1 and 0)
 * @a_idk scripting
 *
 * Return: NADA!
 */

void bit_imp(int ar[], int first, int n, int order, int sz)
{
	int ctr;

	if (n > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n, sz);
			print_array(&ar[first], n);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n, sz);
			print_array(&ar[first], n);
		}

		ctr = n / 2;
		bit_imp(ar, first, ctr, 1, sz), bit_imp(ar, first + ctr, ctr, 0, sz);
		bit_recurse(ar, first, n, order);

		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n, sz);
			print_array(&ar[first], n);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n, sz);
			print_array(&ar[first], n);
		}
	}
}


/**
 * bitonic_sort - general function that calls for the implementation
 * of the bitonic sort algorithm
 * @array: the array
 * @size: the array size
 * @a_idk scripting
 *
 * Return: NADA!
 */

void bitonic_sort(int *array, size_t size)
{
	/* initializing variable */
	int seq = 1;

	/* Checking for NULL and 1 element list */
	if (!array || size < 2)
		return;

	bit_imp(array, 0, size, seq, size);

}
