#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @head: A pointer to the head of the stack.
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
