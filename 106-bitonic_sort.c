#include "sort.h"

/**
 * swap - Swap elements of an array
 * @array: The array to swap it's elements
 * @left: Element at index left
 * @right: Element at index right
 *
 * Return: Nothing / Void
 */
void swap(int *array, int left, int right)
{
	int temp = array[left];

	array[left] = array[right];
	array[right] = temp;
}
/**
 * bitonic_merge - sort and merge bitonic sequence parts
 * in both ascending or descending order
 * @array: array to sort
 * @l_idx: Starting index of the left splitted array
 * @r_idx: Starting index of the right splitted array
 * @dir: direction to sort either in ascending or descending
 * 1(ascending), 0(decending)
 *
 * Return: Nothing / Void
 */
void bitonic_merge(int *array, int l_idx, int r_idx, int dir)
{
	int i, next, mid;

	mid = (l_idx + r_idx) / 2;
	next = (r_idx - l_idx + 1) / 2;

	if (r_idx - l_idx >= 1)
	{
		for (i = l_idx; i < l_idx + next; i++)
			if (dir == (array[i] > array[i + next]))
				swap(array, i + next, i);

		bitonic_merge(array, l_idx, mid, dir);
		bitonic_merge(array, mid + 1, r_idx, dir);
	}

}
/**
 * bitonic_sequence - recursive function for bitonic sort
 * @array: array to sort
 * @l_idx: Starting index of the left splitted array
 * @r_idx: Starting index of the right splitted array
 * @dir: direction to sort either in ascending or descending
 * 1(ascending), 0(decending)
 * @dir: ascending or descending
 * @size: size of the array
 *
 * Return: Nothing / Void
 */
void bitonic_sequence(int *array, int l_idx, int r_idx, int dir, size_t size)
{
	int mid;

	if (r_idx - l_idx >= 1)
	{
		mid = (r_idx + l_idx) / 2;
		printf("Merging [%d/%lu] ", r_idx - l_idx + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l_idx, r_idx - l_idx + 1);
		bitonic_sequence(array, l_idx, mid, 1, size);
		bitonic_sequence(array, mid + 1, r_idx, 0, size);
		bitonic_merge(array, l_idx, r_idx, dir);
		printf("Result [%d/%lu] ", r_idx - l_idx + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l_idx, r_idx - l_idx + 1);
	}
}

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, 0, size - 1, 1, size);
}
