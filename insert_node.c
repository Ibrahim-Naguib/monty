#include "monty.h"

/**
 * insert_node - Inserts a new node at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be assigned to the new node.
 *
 * Return: void
 */

void insert_node(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (temp)
		temp->prev = new;

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
