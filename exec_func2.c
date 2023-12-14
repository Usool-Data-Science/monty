#include "monty.h"

/**
 * exec_mod -  computes the remainder of the division of the
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
	/*Again skip the top*/
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
	/* Check for range of ascii value */
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

	/*transverse the string on the top node*/
	while (current != NULL && current->n != 0 && current->n >= 0 &&
	current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * exec_rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *first = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		last->next = first;
		first->prev = last;
	}
}

/**
 * exec_rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
