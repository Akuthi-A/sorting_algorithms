#include "sort.h"

/**
 * swap_node - swaps node with previous node
 * @node: node
 * @list: doubly linked list
 *
 * Return: pointer to node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *current;
	
	prev_node = node->prev;
	current = node;

	if (prev_node != NULL)
	{
		prev_node->next = current->next;
	}
	if (current->next != NULL)
	{
		current->next->prev = prev_node;
	}
	current->next = prev_node;
	current->prev = prev_node->prev;

	if (prev_node->prev != NULL)
	{
		prev_node->prev->next = current;
	}
	else
	{
		(*list) = current;
	}

	prev_node->prev = current;

	return current;
}

/**
 * insertion_sort_list - implementation of the insertion sort algo
 * @list: linked list to sort
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t* node;

	if (list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
