#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first element to swap
 * @b: second element to swap
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
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
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
	int pi; /* index of pivot */

	if (low < high) /* base case */
	{
		pi = partition(array, low, high, size);
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
