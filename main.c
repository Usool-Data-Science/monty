#include "monty.h"

int execute_cmd(char *cmd, unsigned int line_number)
{
	int i = 0;
	stack_t *stack = NULL;
	instruction_t commands[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		/* Add more opcodes and functions as needed */
		{"NULL", NULL},
	};

	for (i = 0; commands[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, commands[i].opcode) == 0)
		{
			commands[i].f(&stack, line_number);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}

int file_reader(const char *file)
{
	char *cmd = NULL;
	char *file_arg = NULL;
	unsigned int line_number = 0;

	FILE *file_ptr = fopen(file, "r");

	if (file_ptr == NULL)
	{
		/* fprintf */
	}

	if (execute_cmd(cmd, line_number))
		return (1);

	data_arg = file_arg;

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
	const char *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = argv[1];

	if (file_reader(file))
		return (1);

	return (0);
}
