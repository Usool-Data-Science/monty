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

/**
 * exit_failure - exit and free memory
 * @global: global ptr
 */
void exit_failure(global_t *global)
{
	if (global != NULL)
	{
		if (global->file_ptr != NULL)
		{
			fclose(global->file_ptr);
		}
		free_stack(global->stack);
		free(global);
	}
	exit(EXIT_FAILURE);
}

/**
 * convertToInt - convert str to int
 * @toInt: str to convert
 * @line_number: line number
 * @command: opcode
 * Return: Value
 */
int convertToInt(char *toInt, unsigned int line_number, char *command)
{
	int value, i;
	char *temp = toInt;

	if (toInt == NULL)
	{
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		exit_failure(global);
	}

	if (*temp == '+' || *temp == '-')
		temp++;

	for (i = 0; temp[i] != '\0'; i++)
	{
		if (!isdigit(temp[i]))
		{
			fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
			exit_failure(global);
		}
	}

	value = atoi(temp);

	if (value == 0 && temp[0] != '0')
	{
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		exit_failure(global);
	}

	if (toInt[0] == '-')
		return (value * -1);
	return (value);
}
