#include "monty.h"

/**
 * _pchar - Prints the ASCII value at the top of the stack as a character.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _pchar(stack_t **head, unsigned int line_num)
{
	stack_t *current;

	current = *head;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
