#include "monty.h"

/**
 * get_func - function that selects the correct function to perform
 * @opcode: -holds the value of the opcode
 * Return: (void)
 */

void (*get_func(char *opcode)) (stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
