#include "monty.h"

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
	FILE *sup_file = NULL;
	
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
}
