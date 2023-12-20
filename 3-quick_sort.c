#include "sort.h"

/**
 * swap - Swap two integers.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an array using the Lomuto scheme
 * @array: the array to partition
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 * Return: the final index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;

	for (int y = low; y < high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			swap(&array[x], &array[y]);
			if (x != y)
			print_array(array, size);
		}
	}
	swap(&array[x + 1], &array[high]);
	if (x + 1 != high)
		print_array(array, size);
	return (x + 1);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending
 * order using recursion
 * @array: the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: the size of the array
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using Quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
