#include "sort.h"
#include <stdio.h>

/**
 * swap_backward - check backward and swap.
 *
 * @val: list
 *
 **/
void swap_backward(listint_t *val)
{
	listint_t *tmp, *head;

	while (val->prev != NULL)
	{
		if (val->n < val->prev->n)
		{
			tmp = val->prev->prev;
			val->prev->next = val->next;
			val->next = val->prev;
			val->prev->prev = val;
			val->prev = tmp;
			val->next->next->prev = val->next;
			if (tmp != NULL)
				tmp->next = val;
			head = val;
			while (head->prev != NULL)
				head = head->prev;
			print_list(head);
		}
		else
			val = val->prev;
	}
}


/**
 * swap_forward -swap two nodes left to
 * rigth position
 * @val: list
 *
 **/
void swap_forward(listint_t *val)
{
	listint_t *tmp, *head;

	tmp = val->prev; /*pointer to node previus */

	if (tmp != NULL)
	{
		tmp->next = val->next;
		val->next->prev = tmp;
	}
	else
		val->next->prev = NULL;

	val->prev = val->next;

	if (val->next->next != NULL)
	{
		val->next = val->next->next;
		val->prev->next = val;
		val->next->prev = val;
	}
	else
	{
		val->next->next = val;
		val->next = NULL;
	}

	head = val;

	while (head->prev != NULL)
		head = head->prev;
	print_list(head);
	swap_backward(val->prev);
}

/**
 * insertion_sort_list -sort a double linked list
 * with an insert algorithm.
 * @list: list
 *
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *val;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;

	val = *list;

	while (val->next != NULL)
	{
		if (val->n > val->next->n)
		{
			swap_forward(val);
		}
		else
			val = val->next;
	}

	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
