#include "monty.h"

stack_t *push(stack_t **stack, int n)
{
	stack_t *new;

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

	return (new);
}

size_t pall(stack_t **h)
{
	size_t i = 0;
	stack_t *current = *h;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}

	return (i);
}