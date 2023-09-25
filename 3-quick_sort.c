#include <stdio.h>
#include "sort.h"

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
