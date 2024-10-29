#include "sort.h"

/**
  * swap_nodes - fun to swap nodes
  *
  * @list: originl list
  * @node1: nodr to be swapped
  * @node2: 2nd node to swapped
  * Return: void
  */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	temp = node2->next;
	node2->next = node1->next;
	node1->next = temp;

	node2->prev = node1->prev;
	node1->prev = node2;

	if (node2->next)
		node2->next->prev = node2;

	if (node1->prev)
		node1->prev->next = node1;
	print_list(*list);
}

/**
  * insertion_sort_list - sort list using insertiion sort
  *
  * @list: unsortled double linked list
  * Return: void
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur_node;
	if (list == NULL || *list == NULL)
		return;

	cur_node = *list;

	while (cur_node)
	{
		listint_t *next_node = cur_node->next;

		while (cur_node->prev && cur_node->n < cur_node->prev->n)
			swap_nodes(list, cur_node->prev, cur_node);

		cur_node = next_node;
	}
}
