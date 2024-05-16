#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = list;
	skiplist_t *node = list;

	if (list == NULL)
		return (NULL);

	while (node->express != NULL && node->express->n < value)
	{
		prev = node;
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
	}

	if (node->express != NULL)
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, node->index);

	while (prev != NULL && prev->index <= node->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (prev->next != NULL)
		prev = prev->next;
		else
			break;
	}

	return (NULL);
}
