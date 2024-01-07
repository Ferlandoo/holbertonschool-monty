#include "monty.h"

/**
 * add - function that adds the top two elements of the stack
 * @stack: holds the value of the stack
 * @line_number: holds the value for the line number
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop - function that does nothing
 * @stack: -holds the value of the stack
 * @line_number: -holds the value for the line number
 * Return: (void)
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * free_stack - function that frees the stack
 * @stack: -holds the value of the stack
 * Return: (void)
*/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
