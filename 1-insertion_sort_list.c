#include "sort.h"

/**
 * swap_node - swaps node with previous node
 * @node: node
 * @list: list
 *
 * Return: pointer to node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *current;

	prev_node = node->prev;
	current = node;
	prev_node->next = current->next;
	if (current->next)
	{
		current->next->prev = prev_node;
	}

	current->next = prev_node;

}
