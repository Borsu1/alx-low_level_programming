#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node, starting from 0.
 *
 * Return: Pointer to the nth node of the linked list,
 * or NULL if it does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
	if (head == NULL)
	return (NULL);
	head = head->next;
	}add_nodeint_end(&head, 3);
	return (head);
}
