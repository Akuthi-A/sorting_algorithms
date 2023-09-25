#include "sort.h"

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
