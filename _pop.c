#include "monty.h"

/**
 * _pop - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *current;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = current->next;
	free(current);
}
