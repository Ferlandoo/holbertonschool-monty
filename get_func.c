

/**
 * get_op - selects the correct function to perform the operation
 * @token: The operator passed as an argument to the program
 *
 * Return: A pointer to the function that corresponds to the operator,
 *         or NULL if no such function is found.
 */

void (*get_op(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_funcs[] = {
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

	while (op_funcs[i].opcode)
	{
		if (strcmp(token, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
		i++;
	}
	return (NULL);
}
