#include "monty.h"

void exc_push(stack_t **stack, unsigned int line_number)
{
	int data = convertToInt(data_arg, line_number, "push");

	(void)stack;
	(void)line_number;
	(void)data;
	/*
	push
		loop read_line
		while (1)
		{

		}
	*/
	/* then access it here with the value i passed to it earlier */
}


void exec_pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
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
