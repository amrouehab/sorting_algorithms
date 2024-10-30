#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merges two subarrays in a bitonic sequence
 * @array: The array to be merged
 * @size: Number of elements in @array
 * @low: Start index of the subarray
 * @count: Number of elements to be merged
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if (dir == (array[i] > array[i + k]))
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        bitonic_merge(array, size, low, k, dir);
        bitonic_merge(array, size, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts an array using Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Start index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, size, low, k, 1);
        bitonic_sort_recursive(array, size, low + k, k, 0);

        bitonic_merge(array, size, low, count, dir);

        printf("Result [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 0, size, 1);
}
