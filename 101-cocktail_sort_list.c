#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ftmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = ftmp;
	else
		*list = ftmp;
	ftmp->prev = (*shaker)->prev;
	(*shaker)->next = ftmp->next;
	if (ftmp->next != NULL)
		ftmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = ftmp;
	ftmp->next = *shaker;
	*shaker = ftmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ftmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = ftmp;
	else
		*tail = ftmp;
	ftmp->next = (*shaker)->next;
	(*shaker)->prev = ftmp->prev;
	if (ftmp->prev != NULL)
		ftmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = ftmp;
	ftmp->prev = *shaker;
	*shaker = ftmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ftail, *fshaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ftail = *list; ftail->next != NULL;)
		ftail = ftail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (fshaker = *list; fshaker != ftail; fshaker = fshaker->next)
		{
			if (fshaker->n > fshaker->next->n)
			{
				swap_node_ahead(list, &ftail, &fshaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (fshaker = fshaker->prev; fshaker != *list;
				fshaker = fshaker->prev)
		{
			if (fshaker->n < fshaker->prev->n)
			{
				swap_node_behind(list, &ftail, &fshaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
