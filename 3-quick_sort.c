#include "sort.h"

/**
 * swap_n_print - Swap 2 integers in an array and print the array
 * @array: The array to swap from
 * @size: The size of the array
 * @x: The first integer
 * @y: The second integer
 *
 * Return: Nothing
 */
void swap_n_print(int *array, int size, int x, int y)
{
	int temp = array[x];

	array[x] = array[y];
	array[y] = temp;
	print_array(array, size);
}

/**
 * lomuto_partition - A type of partitioning scheme that partition
 * arrays into sub arrays
 * @array: The array to be sorted
 * @size: Size of the array
 * @low: Lower bound of the array or starting index
 * @high: Higher bound of the array or last index
 *
 * Return: The index of the real pivot position in the array
 */
int lomuto_partition(int *array, int size, int low, int high)
{
	int pivot, j, i;

	i = low;
	/* Make last element in the array the pivot */
	/* This is the lomuto principle / method */
	pivot = array[high];

	/* keep looping and swapping till all the lowest numbers */
	/* comes before the pivot and the higher numbers after pivot */
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
				swap_n_print(array, size, i, j);
			i++;
		}
	}
	if (i != high)
		swap_n_print(array, size, i, high);

	return (i);

}
/**
 * sort - performs thr actual sorting
 * @array: the array to be sorted
 * @size: The size of the array
 * @low: lower bound of the array
 * @high: higher of the array
 */
void sort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);

		/* Recursively sort the left hand side of the pivot */
		sort(array, size, low, pivot_idx - 1);

		/* Recursively sort the right hand side of the pivot */
		sort(array, size,  pivot_idx + 1, high);
	}
}
/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: Nothing / Void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
