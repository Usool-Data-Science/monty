#include "monty.h"

void exec_push(stack_t **stack, unsigned int line_number)
{
	int data = convertToInt(data_arg, line_number, "push");
	(void)line_number;
	push(stack, data);
}

void exec_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	pall(stack);
}

void exec_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void exec_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
