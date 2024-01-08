#include "monty.h"

/**
 * get_op - selects the correct function to perform the operation
 * @token: the operation to perform
 * Return: pointer to the function that corresponds to the operation
 */

void (*get_op(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
	};
	int i = 0;

	while (op[i].opcode)
	{
		if (strcmp(token, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);
}