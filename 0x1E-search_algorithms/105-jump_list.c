#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers.
 * @list: A pointer to the head of the list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	if (list == NULL)
		return (NULL);

	size_t jump_step = sqrt(size);
	size_t i = 0;
	listint_t *node = list;

	/* Jump through the list */
	while (node->next != NULL && node->next->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		i += jump_step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       i - jump_step, i);

	/* Perform linear search in the range */
	while (node->next != NULL && node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		node = node->next;
	}

	/* Check if the value is found */
	if (node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		return (node);
	}

	return (NULL);
}
