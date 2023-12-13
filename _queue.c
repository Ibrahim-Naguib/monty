#include "monty.h"

/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file.
 */

void _queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	info.lifo = 1;
}

