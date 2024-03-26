#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order
 * @list: Pointer to the linkedlist
 *
 * Return: Nothing or void
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	/* Loop through the whole list */
	while (current != NULL)
	{
		/* Loop through the unsorted sub list, compare with sorted and swap */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* start sorting and add to sorted sub list */
			listint_t *prev_node = current->prev;
			listint_t *next_node = current->next;

			prev_node->next = next_node;

			if (next_node != NULL)
				next_node->prev = prev_node;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			current->next = prev_node;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
