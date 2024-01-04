#include "monty.h"

/**
* get_func - function that returns a pointer to respective function
* @line_number: -holds the value for the line number
* Return: (structures[i].f)
*/

void (*get_func(char *opcode)) (stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t structures[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};
	for (i = 0; structures[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, structures[i].opcode) == 0)
		{
			return (structures[i].f);
		}
	}
}
