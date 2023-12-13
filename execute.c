#include "monty.h"

/**
 * execute - Executes Monty bytecode.
 * @content: The content read from the Monty file.
 * @stack: A pointer to the head of the stack.
 * @line_num: The current line number being executed.
 * @file: File pointer to the Monty file.
 *
 * Return: 0 on success, -1 on failure.
 */

int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t op_funcs[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"queue", _queue}, {"stack", _stack}, {NULL, NULL}
	};

	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	info.arg = strtok(NULL, " \n\t");

	while (op_funcs[i].opcode && op)
	{
		if (strcmp(op, op_funcs[i].opcode) == 0)
		{	op_funcs[i].f(stack, line_num);
			return (0);
		}
		i++;
	}

	if (op && op_funcs[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
