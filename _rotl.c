#include "monty.h"

/**
 * _rotl - Rotates the stack to the top.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _rotl(stack_t **head,  __attribute__((unused)) unsigned int line_num)
{
	stack_t *current = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	(*head) = temp;
}
