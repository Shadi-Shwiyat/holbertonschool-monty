#include "monty.h"

struct global_s glob_var;

/**
 * main - The entry point for the monty program,
 * runs the monty bytecode interpreter
 *
 * @argc: The number arguements supplied to program
 * @argv: Character array of the supplied arguements
 *
 * Return: 0 on success, otherwise exit faliure and
 * return 1
 */

int main(int argc, char *argv[])
{
	stack_t *monty_stack = NULL;
	FILE *sup_file = NULL;
	size_t n = 0;
	char *line_buff = NULL;
	const char delims[] = " \t\n";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	sup_file = fopen(argv[1], "r");
	if (!sup_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glob_var.file_ref = sup_file;
	glob_var.op_line = 0;
	while (getline(&line_buff, &n, sup_file) != -1)
		tokenizer(line_buff, delims, &monty_stack);
	free_stack(&monty_stack, NULL);
	return (0);
}
