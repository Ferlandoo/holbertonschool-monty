#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: holds the value of the stack
 * @line_number: holds the value for the line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	if (value == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
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
 * @stack: holds the value of the stack
 * @line_number: holds the value for the line number
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
 * @stack: holds the value of the stack
 * @line_number: holds the value for the line number
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
 * @stack: holds the value of the stack
 * @line_number: holds the value for the line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_n;
}
