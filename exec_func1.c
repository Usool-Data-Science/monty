#include "monty.h"

/**
 * exec_swap - swap swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->prev = second;

	*stack = second;
}

/**
 * exec_add - add adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	sum = top->n + second->n;

	second->n = sum;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * exec_sub - add adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sub = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	sub = second->n - top->n;

	second->n = sub;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * exec_nop - does nothing
 * @stack: stack pointer
 * @line_number: line number
 */
void exec_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * free_stack - frees stack
 * @stack: desc
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;

		free(current);
	}
}
