#include "monty.h"

/**
 * free_stack - function frees memory
 * allocated for the stack of monty
 * interpreter
 *
 * @stack: the stack to free
 * @msg: the error message to display
 * if we are freeing based on an error
 *
 * Return: void
 */

void free_stack(stack_t **stack, char *msg)
{
	stack_t *scrubber;

	if (msg)
	{
		if (msg[0] == '!')
		{
			msg++;
			fprintf(stderr, "L%d%s%s\n", glob_var.op_line, msg, glob.op_code);
		}
		else
			fprintf(stderr, "L%d%s", glob_var.op_line, msg);
	}

	if (glob_var.line_ref)
		free(glob_var.line_ref);
	fclose(glob_var.file_ref);

	if (*stack)
	{
		while (*stack)
		{
			scrubber = (*stack)->next;
			free(*stack);
			(*stack) = scrubber;
		}
	}

	if (msg)
		exit(EXIT_FAILURE);
	else
		return;
}
