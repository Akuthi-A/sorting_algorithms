#include "sort.h"

/**
 * bubble_sort - implementation of the bubble sort algo
 * @array: array to sort
 * @size: size of an array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_flag;

	if (array == NULL || size < 2)
		return;

	i = 0;
	j = 0;
	for (i = 0; i < size - 1; i++)
	{
		swap_flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_flag = 1;

				print_array(array, size);
			}
		}
		if (swap_flag == 0)
		{
			break;
		}
	}
}
