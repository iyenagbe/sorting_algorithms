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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *fpivot, fabove, fbelow;

	fpivot = array + right;
	for (fabove = fbelow = left; fbelow < right; fbelow++)
	{
		if (array[fbelow] < *fpivot)
		{
			if (fabove < fbelow)
			{
				swap_ints(array + fbelow, array + fabove);
				print_array(array, size);
			}
			fabove++;
		}
	}

	if (array[fabove] > *fpivot)
	{
		swap_ints(array + fabove, fpivot);
		print_array(array, size);
	}

	return (fabove);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int fpart;

	if (right - left > 0)
	{
		fpart = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, fpart - 1);
		lomuto_sort(array, size, fpart + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
