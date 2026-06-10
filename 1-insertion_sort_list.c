#include "sort.h"

/**
 * swap_nodes - Swaps a node with its previous node
 * @list: Pointer to head of list
 * @node: Node to move backward
 */
static void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev_node;
	listint_t *next_node;

	prev_node = node->prev;
	next_node = node->next;

	prev_node->next = next_node;

	if (next_node)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	node->next = prev_node;

	if (prev_node->prev)
		prev_node->prev->next = node;
	else
		*list = node;

	prev_node->prev = node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}

		current = next;
	}
}
