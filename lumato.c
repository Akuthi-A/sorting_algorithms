#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
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
