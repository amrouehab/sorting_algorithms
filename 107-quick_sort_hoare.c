#include <stdio.h>
#include "sort.h"

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: The array to be partitioned
 * @size: Number of elements in @array
 * @low: Start index of the subarray
 * @high: End index of the subarray
 * Return: The pivot index
 */
size_t hoare_partition(int *array, size_t size, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - Recursively sorts an array using Quick Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Start index of the subarray
 * @high: End index of the subarray
 */
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high)
{
    if (low < high)
    {
        size_t pi = hoare_partition(array, size, low, high);

        quick_sort_recursive(array, size, low, pi);
        quick_sort_recursive(array, size, pi + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, size, 0, size - 1);
}
