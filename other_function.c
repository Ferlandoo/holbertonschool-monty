#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;
	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
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
 * global_free - globally frees memory, previously alocated in the program
 * Return: void
 */

void global_free(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;

	to_free = *global_head;
	while (to_free)
	{
		temp = to_free->next;

		free(to_free);

		to_free = temp;
	}
}
