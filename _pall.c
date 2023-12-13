#include "monty.h"

/**
 * _pall - Prints all elements in the stack.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
