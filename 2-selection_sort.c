#include "sort.h"
/**
 * swap - Swaps values pointed to by integer pointers.
 *
 * @a: Pointer to the first integer variable.
 * @b: Pointer to the second integer variable.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
