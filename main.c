#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		func = get_func(opcode);
		if (func == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_number);
	}
	free_stack(stack);
	free(line);
	fclose(file);
	return (0);
}
