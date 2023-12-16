#include <stdlib.h>
#include "dlistint.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a
 * doubly-linked list.
 * @head: A double pointer to the head of the doubly-linked list.
 * @index: The index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (head == NULL || *head == NULL)
	return (-1);

	for (i = 0; i < index && current != NULL; i++)
	current = current->next;
	if (i != index)
	return (-1);

	if (current->next != NULL)
	current->next->prev = current->prev;

	if (index != 0)
	current->prev->next = current->next;
	else
	*head = current->next;

	free(current);
	return (1);
}
