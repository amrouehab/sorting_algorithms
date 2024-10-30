#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: The array to find the maximum value in
 * @size: Number of elements in @array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}

/**
 * count_sort - Performs counting sort on the array based on the significant digit
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current significant digit (1, 10, 100, ...)
 */
void count_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    if (array == NULL || size < 2)
        return;

    for (exp = 1; max / exp > 0; exp *= 10)
        count_sort(array, size, exp);
}
