#include "sort.h"

/**
 * swap - Swap 2 integers
 * @x: The first integer
 * @y: The second integer
 *
 * Return: Void or nothing
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing or void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* Compare all d element to select the smallest */
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		/* If the smallest is not the one picked earlier */
		/* Swap the new smallest element with the previous one */
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
