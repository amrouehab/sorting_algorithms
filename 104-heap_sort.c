#include <stdio.h>
#include "sort.h"

/**
 * heapify - Builds a max heap from an array
 * @array: The array to be heapified
 * @size: Number of elements in @array
 * @root: The root index of the heap
 * @total_size: Total size of the array (for printing purposes)
 */
void heapify(int *array, size_t size, size_t root, size_t total_size)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        print_array(array, total_size);
        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
