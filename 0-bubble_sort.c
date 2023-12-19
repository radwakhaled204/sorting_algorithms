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
/**
 * bubble_sort - Bubble sort for integers, prints array after each swap.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size: Size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
			}
		}
	}
}
