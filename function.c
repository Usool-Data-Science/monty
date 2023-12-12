#include "monty.h"

int convertToInt(char *arg, unsigned int line_number, char *command)
{
	int value = atoi(arg);

	if (value == 0 && *arg != '0')
	{
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		exit(EXIT_FAILURE);
	}

	return (value);
}
