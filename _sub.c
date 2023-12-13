#include "monty.h"

/**
 * _sub - Subtracts the top element of the stack from the second top element.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int sub, i;

	temp = *head;
	for (i = 0; temp != NULL; i++)
		temp = temp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
