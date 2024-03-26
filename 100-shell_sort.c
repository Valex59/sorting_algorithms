#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 * order using shell sort with the knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing or void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Generate the gap base of the knuth sequence */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	/* Reduce the gap by dividing by 3 per iteration */
	for (gap = gap / 3; gap > 0; gap /= 3)
	{
		/* Ensure the gap is within the array index */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
