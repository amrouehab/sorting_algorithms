#ifndef SORT_H
#define SORT_H

#include <stddef.h> /* For size_t */

/* Structure for a doubly linked list node */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function Prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);  
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high);
size_t hoare_partition(int *array, size_t size, size_t low, size_t high);

#endif /* SORT_H */

