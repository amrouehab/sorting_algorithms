#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @temp: Temporary array to hold the merged result
 * @left: Start index of the first subarray
 * @mid: End index of the first subarray
 * @right: End index of the second subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = left;

    printf("Merging...\n[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts an array using Merge Sort
 * @array: The array to be sorted
 * @temp: Temporary array to hold the merged result
 * @left: Start index of the subarray
 * @right: End index of the subarray
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid + 1, right);

        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size - 1);

    free(temp);
}
