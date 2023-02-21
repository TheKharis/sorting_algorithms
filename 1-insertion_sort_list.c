#include "sort.h"

/**
 * insertion_sort_list - implement insertion sort algorithm in a doubly LL
 * @list: double pointer to list to head of list
 *
 * Return: list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr && curr->prev; curr = curr->next)
	{
		for (; curr && curr->prev && curr->n < curr->prev->n;
				curr = curr->prev)
		{
			temp = curr->prev;
			swap(list, temp, curr);
			print_list(*list);
			curr = curr->next;
		}
	}
}

/**
 * swap - swap two nodes
 * @head: head node of DLL;
 * @nd_1: first node
 * @nd_2: second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *nd_1, listint_t *nd_2)
{
	listint_t *prev, *next;

	prev = nd_1->prev;
	next = nd_2->next;

	if (prev != NULL)
		prev->next = nd_2;
	else
		*head = nd_2;

	nd_1->prev = nd_2;
	nd_1->next = next;
	nd_2->prev = prev;
	nd_2->next = nd_1;
	if (next)
		next->prev = nd_1;
}
