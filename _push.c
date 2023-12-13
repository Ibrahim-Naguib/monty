#include "monty.h"

/**
 * _push - Push a new node onto the stack.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _push(stack_t **head, unsigned int line_num)
{
	int n, i = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			i++;
		for (; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(info.file);
			free(info.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(info.arg);
	if (info.lifo == 0)
		insert_node(head, n);
	else
		insert_queue(head, n);
}
