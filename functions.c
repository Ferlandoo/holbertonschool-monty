#include "monty.h"

/**
 * push - pushes new node to the end of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;

	num = strtok(NULL, DELIMS);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(num);
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
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

	if (stack == NULL || *stack == NULL)
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

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	*stack = temp;
}
