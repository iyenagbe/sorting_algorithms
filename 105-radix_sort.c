#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int fmax, f;

	for (fmax = array[0], f = 1; f < size; f++)
	{
		if (array[f] > fmax)
			fmax = array[f];
	}

	return (fmax);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int fcount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t f;

	for (f = 0; f < size; f++)
		fcount[(array[f] / sig) % 10] += 1;

	for (f = 0; f < 10; f++)
		fcount[f] += fcount[f - 1];

	for (f = size - 1; (int)f >= 0; f--)
	{
		buff[fcount[(array[f] / sig) % 10] - 1] = array[f];
		fcount[(array[f] / sig) % 10] -= 1;
	}

	for (f = 0; f < size; f++)
		array[f] = buff[f];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int fmax, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	fmax = get_max(array, size);
	for (sig = 1; fmax / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
