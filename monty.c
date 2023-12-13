#include "monty.h"

info_t info = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 256;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	info.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		info.content = content;
		line_num++;

		if (read_line > 0)
		{
			execute(content, &stack, line_num, file);
		}
		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
