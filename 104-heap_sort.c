#include "sort.h"

/**
 * swap - Swap 2 adjacent integers
 * @x: The first integer
 * @y: The second integer
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * sift_down_heapify - This maintains the max-heap property by re-forming
 * max-heap once the max has been removed.
 * @array: The array to create the max-heap from
 * @size: The size of the array
 * @s: The size of the sub tree
 * @idx: The max index of the sub tree in the heap
 *
 * Return: Nothing or void
 */
void sift_down_heapify(int *array, size_t size, size_t s, size_t idx)
{
	size_t left, right, top;

	top = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	/* Compare the new root node elem with its left child elem*/
	/* If the left child elem > root node elem make */
	/* root node idx = left child idx */
	if (left < s && array[left] > array[top])
		top = left;
	if (right < s && array[right] > array[top])
		top = right;

	/* If either either of the children elem > the root node elem */
	/* Swap the root node elem with the child's elem recursively */
	if (top != idx)
	{
		swap(&array[idx], &array[top]);
		print_array(array, size);
		sift_down_heapify(array, size, s, top);
	}
}
/**
 * create_max_heap - Re-build heap i.e rearrange the heap / binary
 * tree extracted from array
 * @array: The array to build heap from
 * @size: The size of the array
 *
 * Return: Nothing/ void
 */
void create_max_heap(int *array, size_t size)
{
	int i = (size / 2) - 1;

	for (; i >= 0; i--)
		sift_down_heapify(array, size, size, (size_t)i);
}
/**
 * heap_sort - Sort an array using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing / void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	/* Build heap */
	create_max_heap(array, size);

	/* Compare and swap heap root i.e last element with first elemnt */
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		if (i != 0)
			print_array(array, size);
		sift_down_heapify(array, size, (size_t)i, 0);
	}
}
