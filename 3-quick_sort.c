#include "sort.h"

/**
 * swap - swaps two elements in an array.
 * @a: first element to swap.
 * @b: second element to swap.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme.
 * @array: the array to partition.
 * @l_idx: the lowest index of the partition.
 * @h_idx: the highest index of the partition.
 * @size: the size of the array.
 * Return: the final index of the par.
 */

int lomuto_partition(int *array, int l_idx, int h_idx, size_t size)
{
	int par = array[h_idx];
	int x = l_idx - 1;

	for (int y = l_idx; y < h_idx; y++)
	{
		if (array[y] <= par)
		{
			x++;
			swap(&array[x], &array[y]);
			if (x != y)
				print_array(array, size);
		}
	}
	swap(&array[x + 1], &array[h_idx]);
	if (x + 1 != h_idx)
		print_array(array, size);
	return (x + 1);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending
 * order using recursion
 * @array: the array to sort
 * @l-idx: the lowest index of the partition to sort
 * @h-idx: the highest index of the partition to sort
 * @size: the size of the array
 */

void quick_sort_rec(int *array, int l_idx, int h_idx, size_t size)
{
	if (l_idx < h_idx)
	{
		int pi = lomuto_partition(array, l_idx, h_idx, size);

		quick_sort_rec(array, l_idx, pi - 1, size);
		quick_sort_rec(array, pi + 1, h_idx, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using Quick sort algorithm
 * @array: the array to sort
 * @l-idx: the lowest index of the partition.
 * @h-idx: the highest index of the partition.
 * @size: the size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
