#include "sort.h"

/**
 * swap - Swap two adjacent nodes
 * @node_1: The node at the back or the first node to be swaped
 * @node_2: The node in front of node_1 i.e second node
 * @list: The doubly linked list
 *
 * Return: Nothing or Void
 */
void swap(listint_t *node_1, listint_t *node_2, listint_t **list)
{
	node_1->next = node_2->next;
	/*If node infornt of node 2 is not the last node*/
	if (node_2->next != NULL)
		node_2->next->prev = node_1;

	/* If the node1 is the first node in the LL i.e the head node*/
	if (node_1->prev == NULL)
	{
		node_2->next = node_1;
		node_1->prev = node_2;
		node_2->prev = NULL;
		*list = node_2; /* make node_2 the head node */
	}
	/*If the node is not the first node in the list*/
	else
	{
		node_1->prev->next = node_2;
		node_2->prev = node_1->prev;
		node_2->next = node_1;
		node_1->prev = node_2;
	}

}
/**
 * cocktail_sort_list - Sort a doubly linked list of integers in
 * ascending order using cocktail shaker sort
 * @list: The linked list to sort
 *
 * Return: Nothing / Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node1, *node2;
	int just_swapped = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node1 = (*list);
	while (just_swapped)
	{
		just_swapped = 0;
		/* Loop forward, compare adjacent node and swap when necessary*/
		while (node1->next != NULL)
		{
			node2 = node1->next;
			if (node1->n > node2->n)
			{
				swap(node1, node2, list);
				just_swapped = 1;
				print_list(*list);
			}
			else
				node1 = node1->next;
		}
		if (just_swapped == 0)
			break;
		 /* Node1 = 2nd to last, loop backward, compare and swap when necessary */
		node1 = node1->prev;
		while (node1->prev != NULL)
		{
			node2 = node1->prev;
			if (node1->n < node2->n)
			{
				swap(node2, node1, list);
				just_swapped = 1;
				print_list(*list);
			}
			else
				node1 = node1->prev;
		}
		node1 = node1->next;
	}
}
