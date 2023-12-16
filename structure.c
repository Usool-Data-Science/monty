#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: pointer to stack
 * @line_number: line number
 * @data_arg: data arg
 */
void push(stack_t **stack, unsigned int line_number, char *data_arg)
{
	stack_t *new;
	int n = convertToInt(data_arg, line_number, "push");

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_failure(global);
	}

	new->n = n;
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		new->next = NULL;
	}

	*stack = new;
}

/**
 * enqueue - pushes an element to the stack.
 * @stack: pointer to stack
 * @line_number: line number
 * @data_arg: data arg
 */
void enqueue(stack_t **stack, unsigned int line_number, char *data_arg)
{
	stack_t *new;
	stack_t *rear = *stack;
	int n = convertToInt(data_arg, line_number, "push");

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_failure(global);
	}

	new->n = n;
	new->next = NULL;

	while (rear != NULL && rear->next != NULL)
	{
		rear = rear->next;
	}
	if (rear == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->prev = rear;
		rear->next = new;
	}
}

/**
 * exec_stack - pushes an element to the stack.
 * @stack: pointer to stack
 * @line_number: line number
 * @data_arg: data arg
 */
void exec_stack(stack_t **stack, unsigned int line_number, char *data_arg)
{
	(void)stack;
	(void)line_number;
	(void)data_arg;

	global->mode = 1;
}

/**
 * exec_queue - pushes an element to the stack.
 * @stack: pointer to stack
 * @line_number: line number
 * @data_arg: data arg
 */
void exec_queue(stack_t **stack, unsigned int line_number, char *data_arg)
{
	(void)stack;
	(void)line_number;
	(void)data_arg;

	global->mode = 0;
}
