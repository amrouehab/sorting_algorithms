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

#endif /* SORT_H */

