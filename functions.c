
/**
 * push - function that pushes an element to the stack
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value = NULL;
	int i = 0;

	value = strtok(NULL, " \n\t");
	if (value == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (value[i] != '\0')
	{
		if (value[0] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (isdigit(value[i]) == 0)
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - function that prints all the values on the stack
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - function that prints the value at the top of the stack
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - function that removes the top element of the stack
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap - function that swaps the top two elements of the stack
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int temp_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
