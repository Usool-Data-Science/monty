#include "monty.h"

/**
 * exec_push - pushes an element to the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n = convertToInt(data_arg, line_number, "push");
	printf("data: %d\n", n);											/* print */

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	} else
		new->next = NULL;

	*stack = new;
	printf("new->n: %d, (*stack)->n: %d\n", new->n, (*stack)->n);									/* print */

	if ((*stack)->next != NULL)
		printf("new->n: %d, (*stack)->n: %d\n", new->n, (*stack)->next->n);
}

/**
 * exec_pall - prints all the values on the stack
 * 	starting from the top of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pall(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}

	printf("node number: %lu\n", i);
}

/**
 * exec_pint - print top opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * exec_pop - pop opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
