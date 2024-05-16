#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip;

	if (list == NULL)
		return (NULL);

	for (skip = list; skip->express != NULL; skip = skip->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", skip->index, skip->n);
		if (skip->express->n >= value)
			break;
	}

	printf("Value checked at index [%lu] = [%d]\n", skip->index, skip->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
		skip->index, skip->express ? skip->express->index : skip->index);

	for (; skip != NULL; skip = skip->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", skip->index, skip->n);
		if (skip->n == value)
			return (skip);
	}

	return (NULL);
}
