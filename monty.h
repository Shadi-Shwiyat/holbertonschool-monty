#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

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
 * struct global_s - global struct
 * @op_code: the opcode
 * @op_arg: associated argument if applicable
 * @op_line: line of inbound file
 * @line_ref: pointer to line
 * @file_ref: pointer to FILE
 * Description: The Way
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	char *op_code;
	char *op_arg;
	unsigned int op_line;
	char *line_ref;
	FILE *file_ref;
} global_t;

extern struct global_s glob_var;

/* defined in freedom.c */
void free_stack(stack_t **stack, char *msg);

/* defined in instructions.c */
void get_func(stack_t **stack);

/* defined in tokenizer.c */
void tokenizer(char *line_buff, const char *delims, stack_t **monty_stack);

/* defined in opcodes.c */
void push_monty(stack_t **stack, unsigned int line_number);
void pall_monty(stack_t **stack, unsigned int line_number);
void pint_monty(stack_t **stack, unsigned int line_number);
void pop_monty(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void add_monty(stack_t **stack, unsigned int line_number);
void nop_monty(stack_t **stack, unsigned int line_number);

#endif
