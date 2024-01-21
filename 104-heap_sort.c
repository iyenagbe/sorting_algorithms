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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, flarge;

	left = 2 * root + 1;
	right = 2 * root + 2;
	flarge = root;

	if (left < base && array[left] > array[flarge])
		flarge = left;
	if (right < base && array[right] > array[flarge])
		flarge = right;

	if (flarge != root)
	{
		swap_ints(array + root, array + flarge);
		print_array(array, size);
		max_heapify(array, size, base, flarge);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int f;

	if (array == NULL || size < 2)
		return;

	for (f = (size / 2) - 1; f >= 0; f--)
		max_heapify(array, size, size, f);

	for (f = size - 1; f > 0; f--)
	{
		swap_ints(array, array + f);
		print_array(array, size);
		max_heapify(array, size, f, 0);
	}
}
