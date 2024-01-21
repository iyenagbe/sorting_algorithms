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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t f, fjump = seq / 2;

	if (seq > 1)
	{
		for (f = start; f < start + fjump; f++)
		{
			if ((flow == FUP && array[f] > array[f + fjump]) ||
			    (flow == FDOWN && array[f] < array[f + fjump]))
				swap_ints(array + f, array + f + fjump);
		}
		bitonic_merge(array, size, start, fjump, flow);
		bitonic_merge(array, size, start + fjump, fjump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t fcut = seq / 2;
	char *fstr = (flow == FUP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, fstr);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, fcut, FUP);
		bitonic_seq(array, size, start + fcut, fcut, FDOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, fstr);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, FUP);
}
