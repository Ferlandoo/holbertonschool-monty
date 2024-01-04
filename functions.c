#include "monty.h"

/**
 * add -adds the top 2 values of the stack
 * @stack: -points to the head of the stack
 * @line_number: -holds the value of the line
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;
	int nr_nodes = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d\n>: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;

	while (tmp != NULL)
	{
		nr_nodes++;
		tmp = tmp->next;
	}
	if (nr_nodes < 2)
	{
		fprintf(stderr, "L<%d\n>: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	free(tmp);
}

/**
* pall -prints all the values of the stack
* @stack: -points to the head of the stack
* @line_number: holds value for the line number in monty file
*/

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *virtual = *stack;
    (void) line_number;

    if (*stack == NULL)
        return;
 
    while(virtual != NULL)
    {
        printf("%d\n", virtual->n);
        virtual = virtual->next;
    }
}

/**
* pint -prints the top value of the stack
* @stack: -points to the head of the stack
* @line_number: -holds value of the line in monty file
*/

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop -pops away the top node
 * @stack: -points to the head of the stack
 * @line_number: -holds value of the line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
* push -pushes a new element into the stack
* @stack: -points to the head of the stack
* @line_number: holds value for the line number in monty file
*/

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *newnode = malloc(sizeof(stack_t));

    if (newnode == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    newnode->n = line_number;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*stack == NULL)
        *stack = newnode;
    else
    {
        newnode->next = *stack;
        (*stack)->prev = newnode;
        *stack = newnode;
    }
}

/**
 * swap -swaps the most recent 2 nodes values
 * @stack: -points to the head of the stack
 * @line_number: -holds the value of the respective line
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int nr_nodes = 0;
	int n;
	stack_t *tmp;

	if (*stack == NULL)
		return;

	tmp = *stack;

	while(tmp != NULL)
	{
		nr_nodes++;
		tmp = tmp->next;
	}
	if (nr_nodes < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;

}
