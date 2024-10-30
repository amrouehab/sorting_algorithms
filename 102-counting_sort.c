#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, i;
    int *count_array, *output;

    if (!array || size < 2)
        return;

    /* Find the maximum element in the array */
    for (i = 0; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate memory for count_array and output */
    count_array = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));

    if (!count_array || !output)
    {
        free(count_array);
        free(output);
        return;
    }

    /* Initialize count_array to zero */
    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Count occurrences of each number */
    for (i = 0; i < (int)size; i++)
        count_array[array[i]]++;

    /* Print count_array after counting elements */
    print_array(count_array, max + 1);

    /* Update count_array for the cumulative counts */
    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    /* Sort elements into output array based on count_array */
    for (i = size - 1; i >= 0; i--)
    {
        output[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy sorted output back to array */
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    /* Free allocated memory */
    free(count_array);
    free(output);
}

