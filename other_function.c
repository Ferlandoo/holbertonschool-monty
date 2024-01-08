

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int result = (*stack)->n + (*stack)->next->n;
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->n = result;
}

/**
 * nop - doesn’t do anything :)
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * free_stack - frees a stack_t stack.
 * @stack: pointer to the head of a stack_t stack.
 * Return: void
 */

void free_stack(stack_t **stack)
{
	while (*stack)
	{
		stack_t *temp = (*stack)->next;

		free(*stack);
		*stack = temp;
	}
}
