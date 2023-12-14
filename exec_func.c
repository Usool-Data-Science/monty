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

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fclose(file_ptr);
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
}

/**
 * exec_pall - prints all the values on the stack
 *	starting from the top of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * exec_pint - print top opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * exec_pop - pop opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	del = *stack;

	if (del->next != NULL)
	{
		*stack = del->next;
		del->next->prev = del->prev;
	}
	else
		*stack = NULL;

	free(del);
}

/**
 * stack_len - gets the len
 * @h: stack pointer
 * Return: the num of node
 */
size_t stack_len(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}

	return (i);
}
