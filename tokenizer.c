#include "monty.h"

/**
 * tokenizer - function tokenizes
 * the bytecode file passed to it in 
 * order to interpret the monty language
 *
 * @line: the line to tokenize
 * @delims: the delimiters to seperate tokens
 * @monty_stack: data structure holding the stack
 *
 * Return: void
 */

void tokenizer(char *line, const char *delims, stack_t **monty_stack)
{
	glob_var.op_line++;
	glob_var.line_ref = line;
	glob_var.op_code = strtok(line, delims);
	if (!glob_var.op_code || glob_var.op_code[0] == '#')
		return;
	glob_var.op_arg = strtok(NULL, delims);
	get_func(monty_stack);
}
