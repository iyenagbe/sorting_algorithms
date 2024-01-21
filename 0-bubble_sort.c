#include "sort.h"

/**
 * swap - swap two values
 * @a: first value
 * @b: second value
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 *					using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int is_swapped = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap(&array[j], &array[j - 1]);
				is_swapped = 1;
				print_array(array, size);
			}
		}
		if (is_swapped == 0)
			break;
		is_swapped = 0;
	}
}
