#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - Compare 2 strings
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 if the same and 1 if str1 > str2
 */
int _strcmp(const char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i]; i++)
		if (str1[i] == '\0')
			return (0);
	return (str1[i] - str2[i]);
}
/**
 * card_value - Get the card values
 * @node: Pointer to the card node
 *
 * Return: A value corresponding to the order of the cards
 */
int card_value(deck_node_t *node)
{
	int val, i;

	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};

	val = 0;

	for (i = 0; i < 13; i++)
		if (_strcmp(node->card->value, values[i]) == 0)
			val = i + 1;

	for (i = 0; i < 4; i++)
		if (_strcmp(kinds[node->card->kind], kinds[i]) == 0)
			val = val + (13 * i);
	/* you havent take care of invalid values and kinds */
	return (val);
}
/**
 * swap - Swap two adjacent nodes
 * @node_1: The node at the back or the first node to be swaped
 * @node_2: The node in front of node_1 i.e second node
 * @deck: The doubly linked deck
 *
 * Return: Nothing or Void
 */
void swap(deck_node_t *node_1, deck_node_t *node_2, deck_node_t **deck)
{
	/* The aim is to bring node_2 at the back of node 1 */
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
		*deck = node_2; /* make node_2 the head node */
	}
	/*If the node is not the first node in the deck*/
	else
	{
		node_1->prev->next = node_2;
		node_2->prev = node_1->prev;
		node_2->next = node_1;
		node_1->prev = node_2;
	}

}
/**
 * sort_deck - Sort a doubly linked deck of cards in
 * ascending order using cocktail shaker sort method
 * @deck: The pointer to deck of card to sort
 *
 * Return: Nothing / Void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node1, *node2;
	int just_swapped = 1;

	if (deck == NULL || (*deck) == NULL || (*deck)->next == NULL)
		return;
	node1 = (*deck);
	while (just_swapped)
	{
		just_swapped = 0;
		/* Loop forward, compare adjacent node and swap when necessary*/
		while (node1->next != NULL)
		{
			node2 = node1->next;
			if (card_value(node1) > card_value(node2))
			{
				swap(node1, node2, deck);
				just_swapped = 1;
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
			if (card_value(node1) < card_value(node2))
			{
				swap(node2, node1, deck);
				just_swapped = 1;
			}
			else
				node1 = node1->prev;
		}
		node1 = node1->next;
	}
}
