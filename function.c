#include "monty.h"

/**
 * convertToInt - convert str to int
 * @toInt: str to convert
 * @line_number: line number
 * Return: Value
 */
int convertToInt(char *toInt, unsigned int line_number, char *command)
{
	int value = atoi(toInt);

	if (value == 0 && *toInt != '0')
	{
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		exit(EXIT_FAILURE);
	}

	return (value);
}
