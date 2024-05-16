#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer on the first node where value is located.
 *         If value is not present in list or if head is NULL, return NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *next;

	if (list == NULL)
		return (NULL);

	next = list->express;
	prev = list;

	printf("Value checked at index [%lu] = [%d]\n",
		next->index, next->n);
	while (next && next->n < value)
	{
		prev = next;
		if (next->express)
		{
			next = next->express;
			printf("Value checked at index [%lu] = [%d]\n",
				next->index, next->n);
		}
		else
		{
			while (next->next)
				next = next->next;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, next->index);
	while (prev && prev->index <= next->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
