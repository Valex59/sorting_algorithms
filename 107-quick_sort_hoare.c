#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - a type of partitioning scheme
 * @array: the array to be sorted
 * @size: size of the array
 * @low: lower bound of the array
 * @high: higher of the array
 *
 * Return: the index_pivot of the array
 */

int hoare_partition(int *array, size_t size, int low, int high)
{
	int right, left, pivot;

	pivot = array[high];

	for (left = low - 1, right = high + 1; left < right;)
	{
		do {
			left++;
		} while (array[left] < pivot);

		do {
			right--;
		} while (array[right] > pivot);

		if (left < right)
		{
			swap_ints(&array[left], &array[right]);
			print_array(array, size);
		}
	}
	return (left);
}

/**
 * hoare_sort - performs thr actual sorting
 * @array: the array to be sorted
 * @size: size of the array
 * @low: lower bound of the array
 * @high: higher of the array
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (high - low > 0)
	{
		pivot_idx = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, pivot_idx - 1);
		hoare_sort(array, size, pivot_idx, high);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
