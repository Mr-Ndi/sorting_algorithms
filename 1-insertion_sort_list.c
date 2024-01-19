#include "sort.h"

/**
  *insertion_sort_list - sorts a doubly linked list using insertion sort
  *@list: the doubly linked list to sort
  *
  *Return: nothing
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *p = *list;
	listint_t *current;
	listint_t *previous;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (p != NULL)
	{
		previous = p->prev;
		current = p;
		p = p->next;

		while (previous != NULL && previous->n > current->n)
		{
			previous->next = current->next;
			if (previous->next != NULL)
				previous->next->prev = previous;
			current->next = previous;
			current->prev = previous->prev;
			if (current->prev != NULL)
				current->prev->next = current;
			previous->prev = current;
			if (previous == *list)
				*list = current;
			previous = current->prev;
			print_list(*list);
		}
	}
}
