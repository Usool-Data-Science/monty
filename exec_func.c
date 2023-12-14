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

	/*Check if the allocation is successful*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		if (file_ptr)
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

	/* Transverse over all node and print n*/
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
	/* Check the top of the stack and print its n*/
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
 * exec_nop - does nothing
 * @stack: stack pointer
 * @line_number: line number
 */
void exec_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
