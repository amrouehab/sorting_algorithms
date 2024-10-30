#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 * @array: Pointer to the array to sort.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    /* Calculate the initial gap using Knuth sequence: 1, 4, 13, 40, 121, ... */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            array[j] = temp;
        }
        /* Print array after each gap reduction */
        print_array(array, size);
        gap /= 3;
    }
}

