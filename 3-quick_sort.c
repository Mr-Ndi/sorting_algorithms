#include "sort.h"

/**
  *swap - swaps to integers
  *@first: first input integer
  *@second: second input integer
  *
  *Return: nothing
  */

void swap(int *first, int *second)
{
	int tmp = *first;

	*first = *second;
	*second = tmp;
}

/**
  *real_quick_sort - implements the Quick sort algorithm to sort an array
  *@array_ptr: pointer to the original array
  *@array: the array to sort
  *@size: the size of the input array
  *@ogsize: size of the original array
  *
  *Return: nothing
  */

void real_quick_sort(int *array_ptr, int *array, size_t size, size_t ogsize)
{
	int a, b, z;

	if (!array || size < 2)
		return;
	a = 0;
	b = size - 2;
	z = size - 1;
	while (a != b)
	{
		if (array[a] < array[z])
			a++;
		if (a != b)
		{
			if (array[b] > array[z])
				b--;
			else if (array[a] > array[z])
			{
				swap(&array[a], &array[b]);
				print_array(array_ptr, ogsize);
				a++;
				if (a != b)
					b--;
			}
		}
	}
	if (array[b] < array[z])
		b++;

	if (array[b] == array[z])
		quick_sort(NULL, 0);
	else
	{
		swap(&array[z], &array[b]);
		print_array(array_ptr, ogsize);
		real_quick_sort(array_ptr, &array[b + 1], z - b, ogsize);
	}
	real_quick_sort(array_ptr, &array[0], b, ogsize);
}

/**
  *quick_sort - implements the Quick sort algorithm to sort an array
  *@array: the array to sort
  *@size: the size of the input array
  *
  *Return: nothing
*/

void quick_sort(int *array, size_t size)
{
	real_quick_sort(array, array, size, size);
}
