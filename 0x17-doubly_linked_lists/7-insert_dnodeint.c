#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the first node of the double linked list.
 * @idx:Index of the list where new node should be added. Index starts at 0.
 * @n: Integer to be included in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int i;

	if (h == NULL)
	return (NULL);

	if (idx != 0)
	{
	current = *h;
	for (i = 0; i < idx - 1 && current != NULL; i++)
	current = current->next;
	if (current == NULL)
	return (NULL);
	}

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
	}
	else
	{
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next != NULL)
	current->next->prev = new_node;
	current->next = new_node;
	}

	return (new_node);
}
