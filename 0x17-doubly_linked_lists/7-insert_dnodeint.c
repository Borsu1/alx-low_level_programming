#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the first node of the list.
 * @idx: Index of the list where the new node should be added,
 * Index starts at 0.
 * @n: Integer to be included in the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL)
	return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	if (idx == 0)
	{
	new_node->next = *h;
	new_node->prev = NULL;
	if (*h != NULL)
	(*h)->prev = new_node;
	*h = new_node;
	return (new_node);
	}

	while (temp != NULL)
	{
	if (i + 1 == idx)
	{
	new_node->next = temp;
	new_node->prev = temp->prev;
	if (temp->prev != NULL)
	temp->prev->next = new_node;
	temp->prev = new_node;
	return (new_node);
	}
	i++;
	temp = temp->next;
	}

	if (i == idx)
	{
		new_node->next = NULL;
		new_node->prev = temp;
		temp->next = new_node;
		return (new_node);
	}

	free(new_node);
	return (NULL);
}
