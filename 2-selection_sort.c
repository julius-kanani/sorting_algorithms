#include "sort.h"

/**
 * make_swap - it swaps two numbers.
 * @a: first integer.
 * @b: second integer.
 **/
void make_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array using
 * selection sort algorithm.
 * @array: a given array.
 * @size: size of the array.
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, pos_min_val;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		pos_min_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[pos_min_val] > array[j])
				pos_min_val = j;
		}
		if (pos_min_val != i)
		{
			make_swap(&array[i], &array[pos_min_val]);
			print_array(array, size);
		}
	}
}
