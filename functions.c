#include "monty.h"

/**
 * push - pushes new node to the end of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *ptr;

	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr = bus.arg;
	if (!ptr || !isdigit(*ptr))
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(ptr);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values from the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = temp->n;
	temp->n = temp->next->n;
	temp->next->n = num;
}
