#include "monty.h"

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
