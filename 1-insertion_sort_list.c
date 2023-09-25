#include "sort.h"

/**
 * insertion_sort_list - sorts  double linked
 * @list: list of double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_index, *previous_index, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	current_index = (*list)->next;

	while (current_index != NULL)
	{
		previous_index = current_index->previous_index;
		temp = current_index;

		while (previous_index != NULL && temp->n < previous_index->n)
		{
			if (temp->next)
				temp->next->previous_index = previous_index;
			previous_index->next = temp->next;
			temp->previous_index = previous_index->previous_index;
			temp->next = previous_index;

			if (previous_index->previous_index)
				previous_index->previous_index->next = temp;
			else
				*list = temp;

			previous_index->previous_index = temp;
			previous_index = temp->previous_index;
			print_list(*list);
		}

		current_index = current_index->next;
	}

}
