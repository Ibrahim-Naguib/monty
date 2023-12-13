#include "monty.h"

/**
 * _mod - Computes the modulus of the second top element and top element.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _mod(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = current->next->n % current->n;
	current->next->n = temp;
	*head = current->next;
	free(current);
}
