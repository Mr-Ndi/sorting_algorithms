#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    size_t i, j, max;
    int *count;

    if (array == NULL || size < 2)
        return;
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > (int)max)
            max = array[i];
    }
    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;
    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
        count[array[i]]++;
    print_array(count, max + 1);
    j = 0;
    for (i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            array[j++] = i;
            count[i]--;
        }
    }
    free(count);
}

