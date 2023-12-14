#include "monty.h"

char *global(char *nothing);
char *data_arg;
FILE *file_ptr;
stack_t *stack = NULL;

/**
 * execute_cmd - sort execute command
 * @cmd: command
 * @line_number: line number
 * Return: 1 on success
 */
int execute_cmd(char *cmd, unsigned int line_number)
{
	int i = 0;

	instruction_t commands[] = {
		{"push", exec_push},
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		{"swap", exec_swap},
		{"add", exec_add},
		{"sub", exec_sub},
		{"nop", exec_nop},
		{"div", exec_div},
		{"mul", exec_mul},
		{"mod", exec_mod},
		{"pchar", exec_pchar},
		{"pstr", exec_pstr},
		/* Add more opcodes and functions as needed */
		{NULL, NULL}
	};

	while (commands[i].opcode != NULL)
	{
		if (strcmp(cmd, commands[i].opcode) == 0)
		{
			commands[i].f(&stack, line_number);
			return (1);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	if (file_ptr)
		fclose(file_ptr);
	exit(EXIT_FAILURE);
}

/**
 * file_reader - reads from file
 * @file: file
 * Return: 1 on succes and 0 otherwise
 */
int file_reader(char *file)
{
	char cmd[LENGTH] = "";
	unsigned int line_number = 0;
	char line[LENGTH];
	char *trimmed_line;

	file_ptr = fopen(file, "r");

	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file_ptr) != NULL)
	{
		line_number++;

		if (line[0] == '#' || (line[0] == ' ' && line[1] == '#'))
			continue;

		trimmed_line = strtok(line, " \t\n");
		if (trimmed_line == NULL || trimmed_line[0] == '#')
			continue;

		strncpy(cmd, trimmed_line, sizeof(cmd) - 1);
		data_arg = strtok(NULL, " \t\n");

		execute_cmd(cmd, line_number);
	}
	fclose(file_ptr);
	return (1);
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
	int value;

	if (toInt == NULL)
	{
		if (file_ptr)
			fclose(file_ptr);
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(toInt);

	if (value == 0 && *toInt != '0')
	{
		if (file_ptr)
			fclose(file_ptr);
		fprintf(stderr, "L%u: usage: %s integer\n", line_number, command);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	return (value);
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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = argv[1];

	file_reader(file);

	free_stack(stack);

	return (0);
}
