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

/**
 * exec_pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_value);
}

/**
 * exec_pstr - prints the string starting at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 && current->n >= 0 &&
	current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
