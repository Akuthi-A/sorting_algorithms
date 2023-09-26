#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element after partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
	{
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sorter - helps quick sort in sorting
 * @array: data type to be sorted
 * @low: lowest value in the arr
 * @high: highest value in the arr
 * @size: size of arr
 */
void quick_sorter(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sorter(array, low, pivot - 1, size);
		quick_sorter(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: data type to be used
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sorter(array, 0, size - 1, size);
}
