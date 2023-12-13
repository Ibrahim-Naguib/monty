#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *current;

	current = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = *head;
	current->prev->next = NULL;
	current->prev = NULL;
	(*head)->prev = current;
	(*head) = current;
}
