#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *current;
	int len = 0, temp;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
