#include "monty.h"

int execute_cmd(char *cmd, stack_t **stack, unsigned int line_number, char *arg)
{
	int i = 0;
	instruction_t commands[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		// Add more opcodes and functions as needed
		{"NULL", NULL},
	};
	/*
		include a loop that checks if the cmd is a monty command
		if its not, handle error and return 0
		else return 1 for success
		if it is parse it to the function that handles the command
	*/

	for (i = 0; commands[i].opcode != "NULL"; i++)
	{
		if (strcmp(*cmd, commands[i].opcode) == 0)
		{
			commands[i].f(*stack, line_number, arg);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arg);
	exit(EXIT_FAILURE);
}

int file_reader(const char *file)
{
	char *cmd = NULL;
	char *arg = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	/*
		includes a loop that reads from file
		line by line
		each line would trimmed for white spaces
		pass the pointer opcode, arg
		if the line is empty skip it .
	*/
	if (execute_cmd(cmd, &stack, line_number, arg))
		return (1);

	return (0);
}

/**
 * main - entry point for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: SUCCESS on success FAILURE on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	const char *file = argv[1];

	if (file_reader(file))
		return (EXIT_SUCCESS);
}
