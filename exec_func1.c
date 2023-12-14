#include "monty.h"

/**
 * exec_swap - swap swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_swap(stack_t **stack, unsigned int line_number)
{
	/* Specify the top and the second layer*/
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

	/* Dont forget to reassign the stack*/
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

	/* Put the sum on the second node and drop the first node*/
	second->n = sum;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * exec_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sub = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	sub = second->n - top->n;

	/* Push the result to second node and drop first node*/
	second->n = sub;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * exec_div -  divides the second top element of the stack by
 * the top element of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = second->n / top->n;

	/* Store div result into node 2 and del node 1*/
	second->n = div;

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * exec_mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	mul = second->n * top->n;

	second->n = mul;

	/* Skip the first node and free it*/
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
