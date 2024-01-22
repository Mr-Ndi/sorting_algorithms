#include "sort.h"

/**
  *swap - swaps two doubly linked lists
  *@first: the first list
  *@second: the second list
  *
  *Return: the node put in front is returned
  */

listint_t *swap(listint_t *first, listint_t *second)
{
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	if (second->prev != NULL)
		second->prev->next = second;
	first->prev = second;
	first = second->prev;
	
	return second;
}

/**
  *count_nodes - counts the nodes of a linked list
  *@list: list to deal with
  *
  *Return: the count of the nodes
  */

int count_nodes(listint_t *list)
{
	listint_t *p = list;
	int n = 0;

	while(p != NULL)
	{
		n++;
		p = p->next;
	}

	return (n);
}


/**
  *cocktail_sort_list - Sorts a linked list using 'cocktail shaker' sorting
  *@list: pointer to the doubly linked list to sort
  *
  *Return: nothing
  */

void cocktail_sort_list(listint_t **list)
{
	int n, i;
	listint_t *current;
	listint_t *next;

	if (!list || !(*list))
		return;

	n = count_nodes(*list);
	current = *list;

	while (n >= 2)
	{
		i = 0;
		next = current->next;
		while (i < n - 1)
		{
			if (current->n > next->n)
			{
				if (i != n - 2)
					current = swap(current, next)->next;
				else
					current = swap(current, next);
			print_list(*list);
			}
			else
			{
				if (i != n -2)
					current = next;
			}
			next = current->next;
			i++;
		}
		n--;

		next = current->prev;
		i = 0;
		while(i < n - 1)
		{
			if (current->n < next->n)
			{
				if (i != n - 2)
					current = swap(next, current);
				else
				{
					if (next->prev == NULL)
						*list = current;
					current = swap(next, current)->next;
				}
			print_list(*list);
			}
			else
			{
				if (i != n - 2)
					current = next;
			}
			next = current->prev;
			i++;
		}
		n--;
	}
}
