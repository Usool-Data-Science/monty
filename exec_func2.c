#include "monty.h"

/**
 * exec_mod -  computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = second->n % top->n;

	second->n = mod;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
