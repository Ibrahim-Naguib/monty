#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - Structure to hold information for Monty interpreter.
 * @arg: Command-line argument passed to the Monty interpreter.
 * @file: File pointer to the currently opened Monty file.
 * @content: Content read from the Monty file.
 * @flag: Flag indicating whether the file is successfully opened or not.
 *
 * Description: Information structure for Monty interpreter - arg, file,
 * content, and open status.
 */

typedef struct info_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifo;
}  info_t;
extern info_t info;

int execute(char *content, stack_t **head, unsigned int line_num, FILE *file);
void insert_node(stack_t **head, int n);
void insert_queue(stack_t **head, int n);
void free_stack(stack_t *head);


void _push(stack_t **head, unsigned int line_num);
void _pall(stack_t **head, unsigned int line_num);
void _pint(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void _nop(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _mod(stack_t **head, unsigned int line_num);
void _pchar(stack_t **head, unsigned int line_num);
void _pstr(stack_t **head, unsigned int line_num);
void _rotl(stack_t **head, unsigned int line_num);
void _rotr(stack_t **head, unsigned int line_num);
void _queue(stack_t **head, unsigned int line_num);
void _stack(stack_t **head, unsigned int line_num);

#endif /* MONTY_H */
