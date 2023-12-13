#include "monty.h"

char *strdup(const char *s);
char *data_arg;

int execute_cmd(char *cmd, unsigned int line_number, stack_t *exec_stack)
{
	int i = 0;
	instruction_t commands[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		/* Add more opcodes and functions as needed */
	};

	while (commands[i].opcode != NULL)
	{
		if (strcmp(cmd, commands[i].opcode) == 0)
		{
			commands[i].f(&exec_stack, line_number);
			/* printf("searching ...\n"); */											/* print */
			return (1);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}

/**
 * file_reader - */
int file_reader(char *file, stack_t **stack)
{
	char *cmd = NULL;
	unsigned int line_number = 0;
	char line[LENGTH];
	char *trimmed_line;

	FILE *file_ptr = fopen(file, "r");

	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file_ptr) != NULL)
	{
		line_number++;

		trimmed_line = strtok(line, " \t\n");
		if (trimmed_line == NULL)
			continue;

		cmd = strdup(trimmed_line);
		data_arg = strtok(NULL, " \t\n");

		if (!execute_cmd(cmd, line_number, *stack))
		{
			fprintf(stderr, "Error executing command on line %d\n", line_number);
			exit(EXIT_FAILURE);
		}
		/* printf("cmd: %s, line number: %u, data_arg: %s\n", cmd, line_number, data_arg); */					/* print */
		free(cmd);
	}

	fclose(file_ptr);
	return (1);
}

/**
 * main - entry point for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: SUCCESS on success FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = argv[1];

	file_reader(file, &stack);
	/* if (file_reader(file))
		printf("file reader return 1\n"); */
	/* print */

	return (0);
}
