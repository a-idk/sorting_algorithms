/* Title: merge_sort.c */
#include "sort.h"

/**
 * mycalloc - function that does the calloc assignment
 * @elems: number of block or elements to be allocated
 * @size: size of memory to be allocated
 * @a_idk scripting
 *
 * Return: NADA!
 */

void *mycalloc(unsigned int elems, unsigned int size)
{
	/* declaring and initializing variable */
	char *ptr, str;
	unsigned int index = 0;

	str = '\0';
	/* check for NULL */
	if (elems == 0 || size == 0)
	{
		return ('\0');
	}
	/* allocating dynamic memory */
	ptr = malloc(size * elems);
	if (ptr == NULL)
	{
		return ('\0');
	}
	for (index = 0; index < (size * elems); index += 1)
	{
		ptr[index] = str;
	}
	return (ptr);
}


/**
 * merging_func - function that merges
 * @part1: first part to mid part
 * @temp: temporary array
 * @f_elems: first element position
 * @center: array middle
 * @l_elem: last element position
 */

void merging_func(int *part1, int *temp, int f_elems, int center, int l_elem)
{
	/* variable assignment */
	int lt_size, rt_size, *lt_arr, *rt_arr, lt, rt;
	int idx = 0;

	lt_size = center - f_elems + 1, rt_size = l_elem - center;
	lt_arr = &temp[0], rt_arr = &temp[rt_size];
	for (lt = 0; lt < lt_size; lt += 1)
		lt_arr[lt] = part1[f_elems + lt];
	for (rt = 0; rt < rt_size; rt += 1)
		rt_arr[rt] = part1[1 + rt + center];
	lt = 0;
	rt = 0;
	idx = f_elems;
	while ((rt < rt_size) && (lt < lt_size))
	{
		if (rt_arr[rt] >= lt_arr[lt])
			part1[idx] = lt_arr[lt], lt = lt + 1;
		else
			part1[idx] = rt_arr[rt], rt = rt + 1;
		idx = idx + 1;
	}
	while (lt_size > lt)
	{
		part1[idx] = lt_arr[lt];
		lt = lt + 1, idx = idx + 1;
	}
	while (rt < rt_size)
	{
		part1[idx] = rt_arr[rt];
		rt = rt + 1, idx = idx + 1;
	}
	printf("Merging...\n"), printf("[left]: "), print_array(lt_arr, lt);
	printf("[right]: "), print_array(rt_arr, rt), printf("[Done]: ");
	print_array(&part1[f_elems], lt + rt);
}


/**
 * sorts_array - funct that uses merge sort algorithm to sort array
 * of ints in ascending order
 * @ar: array of ints
 * @temp: temporary array
 * @f_el: first element
 * @l_el: last element
 * @a_idk scripting
 *
 * Return: NADA!
 */

void sorts_array(int *ar, int *temp, int f_el, int l_el)
{
	/* declaring variable */
	int ctr = (f_el + l_el) / 2;

	if ((f_el + l_el) % 2 == 0)
	{
		ctr = ctr - 1;
	}
	if (ctr >= f_el)
	{
		sorts_array(ar, temp, f_el, ctr), sorts_array(ar, temp, ctr + 1, l_el);
		merging_func(ar, temp, f_el, ctr, l_el);
	}
}


/**
 * merge_sort - function that calls other functions to sorts array of ints
 * using rhe merge sort algorithm
 * @size: list size
 * @array: ints array
 * @a_idk scripting
 *
 * Return: NADA!
 */

void merge_sort(int *array, size_t size)
{
	/* declaring variable */
	int *temp;

	/* checking for NULL and 1 element */
	if (!array || size < 2)
	{
		return;
	}
	temp = mycalloc(size, sizeof(int));
	sorts_array(array, temp, 0, size - 1), free(temp);
}
