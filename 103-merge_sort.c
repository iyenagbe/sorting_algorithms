#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t f, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (f = front, j = mid; f < mid && j < back; k++)
		buff[k] = (subarr[f] < subarr[j]) ? subarr[f++] : subarr[j++];
	for (; f < mid; f++)
		buff[k++] = subarr[f];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (f = front, k = 0; f < back; f++)
		subarr[f] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t fmid;

	if (back - front > 1)
	{
		fmid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, fmid);
		merge_sort_recursive(subarr, buff, fmid, back);
		merge_subarr(subarr, buff, front, fmid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *fbuff;

	if (array == NULL || size < 2)
		return;

	fbuff = malloc(sizeof(int) * size);
	if (fbuff == NULL)
		return;

	merge_sort_recursive(array, fbuff, 0, size);

	free(fbuff);
}
