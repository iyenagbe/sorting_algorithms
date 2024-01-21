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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *fmin;
	size_t f, fj;

	if (array == NULL || size < 2)
		return;

	for (f = 0; f < size - 1; f++)
	{
		fmin = array + f;
		for (fj = f + 1; fj < size; fj++)
			fmin = (array[fj] < *fmin) ? (array + fj) : fmin;

		if ((array + f) != fmin)
		{
			swap_ints(array + f, fmin);
			print_array(array, size);
		}
	}
}
