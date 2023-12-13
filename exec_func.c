#include "monty.h"

/**
 * exec_push - push opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_push(stack_t **stack, unsigned int line_number)
{
	int data = convertToInt(data_arg, line_number, "push");
	/* printf("data: %d\n", data); */											/* print */
	(void)line_number;
	push(stack, data);
}

/**
 * exec_pall - print all opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	pall(stack);
}

/**
 * exec_pint - print top opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * exec_pop - pop opcode function
 * @stack: pointer to stack
 * @line_number: line number
 */
void exec_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
