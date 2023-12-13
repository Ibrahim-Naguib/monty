#include "monty.h"

/**
 * _pstr - Prints the string starting at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _pstr(stack_t **head, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;

	current = *head;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
