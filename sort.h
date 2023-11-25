#ifndef _SORT_H
#define _SORT_H

/* STANDARD LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

/* DEFINED DATA STRUCTURE */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* MANDATORY PROTOTYPES */
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swapping(int *array, size_t before, size_t after);
void lomuto_part(int *array, size_t start, size_t end, size_t size);
void quick_sort(int *array, size_t size);


/* ADVANCED PROTOTYPES */
void shell_sort(int *array, size_t size);
void swapping2(listint_t **nd, listint_t **lst);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void *mycalloc(unsigned int elems, unsigned int size);
void merging_func(int *part1, int *temp, int f_elems, int center, int l_elem);
void sorts_array(int *ar, int *temp, int f_el, int l_el);
void merge_sort(int *array, size_t size);
void _swift(int *arr, size_t init, size_t size, size_t idx);
void heap_sort(int *array, size_t size);
int maxVal(int *array, int size);
void sorting(int *array, size_t size, int ex, int *temp);
void radix_sort(int *array, size_t size);
void bit_recurse(int ar[], int first, int elem, int order);
void bit_imp(int ar[], int first, int n, int order, int sz);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* sort.h */
