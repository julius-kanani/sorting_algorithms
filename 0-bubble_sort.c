#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array for to sort
 * @size: number elements of array
 * Return: sorts new array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t flag;
	size_t temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}

		}
		if (flag == 0)
			break;
	}
}
