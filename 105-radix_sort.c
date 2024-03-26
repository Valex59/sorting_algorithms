#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radixCounting_sort - implentation of counting sort
 * @array: the array to be sorted
 * @size: size of the array
 * @pos: position of the array
 */
void radixCounting_sort(int *array, size_t size, int pos)
{
	int i, max, *count, *sorted;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);

	sorted = malloc(sizeof(int) * size);
	if (sorted  == NULL)
		return;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	/* intializing the array count with 0*/
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	/* counting the unique values of the array to be sorted */
	for (i = 0; i < (int)size; i++)
		count[(array[i] / pos) % 10]++;

	/* summing the counts consecutively */
	for (i = 1; i < (int)size + 1; i++)
		count[i] += count[i - 1];

	/* sorting the array into a sorted array*/
	for (i = size - 1; i >= 0; i--)
		sorted[--count[(array[i] / pos) % 10]] = array[i];

	/* Reassignment of the array with the sorted array*/
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int pos, max;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		radixCounting_sort(array, size, pos);
		print_array(array, size);
	}
}
