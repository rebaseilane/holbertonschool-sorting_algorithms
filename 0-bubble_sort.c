#include "sort.h"

/**
 * swap_ints - Swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 */
static void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array using Bubble Sort
 *
 * @array: Array to sort
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}