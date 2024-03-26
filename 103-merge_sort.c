#include "sort.h"
#include <stdlib.h>

/**
 * merge_SubArray - merges the adjacent subarrays
 * @sub_array: smaller array to be sorted
 * @buffer: a copy of the array
 * @low: lowest index
 * @high: highest index
 * @mid: The middle idx
 */
void merge_SubArray(int *sub_array, int *buffer, int low, int mid, int high)
{
	int i = low, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + low, mid - low);

	printf("[right]: ");
	print_array(sub_array + mid, high - mid);

	while (i < mid && j < high)
	{
		if (sub_array[i] < sub_array[j])
		{
			buffer[k] = sub_array[i];
			i++;
		}
		else
		{
			buffer[k] = sub_array[j];
			j++;
		}
		k++;
	}
	while (j < high)
	{
		buffer[k] = sub_array[j];
		j++;
		k++;
	}
	while (i < mid)
	{
		buffer[k] = sub_array[i];
		i++;
		k++;
	}

	for (i = low, k = 0; i < high; i++, k++)
		sub_array[i] = buffer[k];

	printf("[Done]: ");
	print_array(sub_array + low, high - low);
}
/**
 * split_merge_TopDown - splits arrays into subarrays recursively
 * order using the Radix sort algorithm
 * @sub_array: smaller array to be sorted
 * @buffer: a copy of the array
 * @low: lowest index
 * @high: highest index
 */
void split_merge_TopDown(int *sub_array, int *buffer, int low, int high)
{
	if (high - low > 1)
	{
		int mid = (high + low) / 2;

		split_merge_TopDown(sub_array, buffer, low, mid);
		split_merge_TopDown(sub_array, buffer, mid, high);
		merge_SubArray(sub_array, buffer, low, mid, high);
	}
}
/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	split_merge_TopDown(array, buffer, 0, size);
	free(buffer);
}
