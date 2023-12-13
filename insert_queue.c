#include "monty.h"

/**
 * insert_queue - Inserts a new node at the end of the stack (queue).
 * @head: Pointer to the head of the stack.
 * @n: Value to be assigned to the new node.
 */

void insert_queue(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		printf("Error\n");

	new->n = n;
	new->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}

	if (!temp)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		temp->next = new;
		new->prev = temp;
	}
}
