#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge and sort sub arrays
 * @array: The array
 * @left_arr: The left sub array
 * @right_arr: The right sub array
 * @l_size: The size of left sub array
 * @r_size: The size of right sub array
 *
 * Return: Nothing / void
 */
void merge(int *array, int left_arr[], int l_size, int right_arr[], int r_size)
{
	int i, j, k;

	i = j = k = 0;

	while (i < l_size && j < r_size)
	{
		if (left_arr[i] < right_arr[j])
			array[k++] = left_arr[i++];
		else
			array[k++] = right_arr[j++];
	}

	/* check if left_array still has elements left uncompared*/
	while (i < l_size)
		array[k++] = left_arr[i++];

	/* check if right_array still has elements left uncompared */
	while (j < r_size)
		array[k++] = right_arr[j++];
}
/**
 * loop - Loop and print the element in an array
 * @i: The loop initializer value
 * @condition: Fondition for loop
 * @array: The array to print its element
 *
 * Return: Nothing
 */
void loop(int i, int condition, int *array)
{
	int k;

	for (k = i; k < condition; k++)
	{
		if (i < condition - 1)
			printf("%d, ", array[k]);
		else
			printf("%d", array[k]);
	}
}

/**
 * merge_sort - Merge and sort sub arrays
 * @array: The array
 * @size: The size of the array
 *
 * Return: Nothing / void
 */
void merge_sort(int *array, int size)
{
	int i, j, middle, *left_array, *right_array;

	if (array == NULL || size < 2)
		return;
	if (size <= 1)/* Base case for the recurssion */
		return;
	middle = size / 2; /* get the middle of the array */
	left_array = malloc(sizeof(int) * middle); /*Dynamically allocate space for*/
	if (left_array == NULL) /* the left subarray */
		return;
	right_array = malloc(sizeof(int) * (size - middle)); /* right sub array */
	if (right_array == NULL)
	{
		free(left_array);
		return;
	}
	for (i = 0; i < middle; i++) /* Copy left & right of the divided */
		left_array[i] = array[i]; /*main array to left & right subarray */
	for (j = middle; j < size; j++)
		right_array[j - middle] = array[j];
	merge_sort(left_array, middle); /*Recurssively split the left & right array */
	merge_sort(right_array, size - middle); /* into sub arrays untill size is 1 */
	printf("Merging...\n"); /* Print elements in left & right sub array */
	printf("[left]: ");
	loop(0, middle, left_array);
	printf("\n[right]: ");
	for (j = middle; j < size; j++)
	{
		if (j < size - 1)
			printf("%d, ", right_array[j - middle]);
		else
			printf("%d", right_array[j - middle]);
	}
	printf("\n");
	merge(array, left_array, middle, right_array, size - middle);
	printf("[Done]: "); /* Print the sorted elements in both sub arrays */
	loop(0, size, array);/* Print the sorted elements in both sub arrays */
	printf("\n");
	free(left_array); /* Free memory allocated */
	free(right_array);
}
