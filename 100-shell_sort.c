#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int ftmp;

	ftmp = *a;
	*a = *b;
	*b = ftmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t fgap, f, j;

	if (array == NULL || size < 2)
		return;

	for (fgap = 1; fgap < (size / 3);)
		fgap = fgap * 3 + 1;

	for (; fgap >= 1; fgap /= 3)
	{
		for (f = fgap; f < size; f++)
		{
			j = f;
			while (j >= fgap && array[j - fgap] > array[j])
			{
				swap_ints(array + j, array + (j - fgap));
				j -= fgap;
			}
		}
		print_array(array, size);
	}
}
