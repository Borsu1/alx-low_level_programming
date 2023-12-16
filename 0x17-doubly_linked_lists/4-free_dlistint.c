#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees an integer from a doubly linked list
 * @head: pointer to the head of the list
 * Description: This function frees an integer from a doubly linked list
 * Parameters: dlist - pointer to the doubly linked list
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
}
