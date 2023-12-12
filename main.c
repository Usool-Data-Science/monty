#include "monty.h"

int execute_cmd(char *cmd, stack_t **stack, unsigned int line_number, char *file_arg)
{
	int i = 0;
	instruction_t commands[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		/* Add more opcodes and functions as needed */
		{"NULL", NULL},
	};

	for (i = 0; commands[i].opcode != "NULL"; i++)
	{
		if (strcmp(*cmd, commands[i].opcode) == 0)
		{
			commands[i].f(*stack, line_number);
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
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	FILE *file_ptr = fopen(file, "r");

	if (file_ptr == NULL)
	{
		//fprintf
	}

	if (execute_cmd(cmd, &stack, line_number, file_arg))
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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	const char *file = argv[1];

	if (file_reader(file))
		return (EXIT_SUCCESS);
}
