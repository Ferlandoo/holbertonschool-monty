#include "monty.h"

/**
* get_func - function that returns a pointer to respective function
* @line_number: -holds the value for the line number
* Return: (structures[i].f)
*/

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t structures[] = {
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

	while (structures[i].opcode != NULL)
	{
		if (strcmp(opcode, structures[i].opcode) == 0)
			return (structures[i].f);
		i++;
	}
	return (NULL);
}
