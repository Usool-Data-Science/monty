#include "monty.h"

void exc_push(stack_t **stack, unsigned int line_number, char *arg)
{
	int data = convertToInt(arg, line_number, "push");
	/*
	push
		loop read_line
		while (1)
		{
			read_line(line_number);

			line_number++;
		}
	*/
}


void exec_pall(stack_t **stack, unsigned int line_number, char *arg)
{

}

void exec_pint(stack_t **stack, unsigned int line_number, char *arg)
{

}

void exec_pop(stack_t **stack, unsigned int line_number, char *arg)
{

}