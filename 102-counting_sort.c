#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *fcount, *fsorted, fmax, f;

	if (array == NULL || size < 2)
		return;

	fsorted = malloc(sizeof(int) * size);
	if (fsorted == NULL)
		return;
	fmax = get_max(array, size);
	fcount = malloc(sizeof(int) * (fmax + 1));
	if (fcount == NULL)
	{
		free(fsorted);
		return;
	}

	for (f = 0; f < (fmax + 1); f++)
		fcount[f] = 0;
	for (f = 0; f < (int)size; f++)
		fcount[array[f]] += 1;
	for (f = 0; f < (fmax + 1); f++)
		fcount[f] += fcount[f - 1];
	print_array(fcount, fmax + 1);

	for (f = 0; f < (int)size; f++)
	{
		fsorted[fcount[array[f]] - 1] = array[f];
		fcount[array[f]] -= 1;
	}

	for (f = 0; f < (int)size; f++)
		array[f] = fsorted[f];

	free(fsorted);
	free(fcount);
}
