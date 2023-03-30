#include "main.h"

/**
 * get_func - function determines the
 * function to run based on the given
 * operation code
 *
 * @stack: a pointer to the stack
 * where the opcode lives
 *
 * Return: void
 */

void get_func(stack_t **stack)
{
	unsigned int i;
	char *errMsg = "!: unknown instruction ";

	instruction_t betty[] = {
		{"pall", pall_monty},
		{"push", push_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{NULL, NULL}
	};

	for (i = 0; betty[i].opcode; i++)
	{
		if (strcmp(betty[i].opcode, glob_var.op_code) == 0)
		{
			betty[i].f(stack, glob_var.op_line);
			return;
		}
	}

	free_stack(stack, errMsg);
}
