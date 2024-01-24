#include "sort.h"

/**
  *merge_sort - sorts an array using merge sort algorithm
  *@array: this is the array to sort
  *@size: this is the size of @array
  *
  *Return: nothing
  */

void merge_sort(int *array, size_t size)
{
	int *half, *p;
	size_t j = 0, k = 0, i, s;

	if (size < 2)
		return;

	p = malloc(sizeof(int) * size);
	s = size - size / 2;
	half = array + size / 2;
	merge_sort(array, size / 2);
	merge_sort(half, s);

	printf("Merging...\n[left]: ");
	print_array(array, size / 2);
	printf("[right]: ");
	print_array(half, s);
	printf("[Done]: ");
	for (i = 0; i < size; i++)
	{
		if (k >= size / 2 || (j < s && array[k] > half[j]))
		{
			p[i] = half[j];
			j++;
		}
		else
		{
			p[i] = array[k];
			k++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = p[i];
	}
	print_array(p, size);
	free(p);
}
