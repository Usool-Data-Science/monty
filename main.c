#include "monty.h"

global_t *global;

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
		{"rotl", exec_rotl},
		{"rotr", exec_rotr},
		/* Add more opcodes and functions as needed */
		{NULL, NULL}
	};

	while (commands[i].opcode != NULL)
	{
		if (strcmp(cmd, commands[i].opcode) == 0)
		{
			commands[i].f(&(global->stack), line_number, global->data_arg);
			return (1);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	if (global->file_ptr)
		fclose(global->file_ptr);
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

	global->file_ptr = fopen(file, "r");

	if (global->file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		fclose(global->file_ptr);
		exit_failure(global);
	}
	while (fgets(line, sizeof(line), global->file_ptr) != NULL)
	{
		line_number++;

		if (line[0] == '#' || (line[0] == ' ' && line[1] == '#'))
			continue;

		trimmed_line = strtok(line, " \t\n");
		if (trimmed_line == NULL || trimmed_line[0] == '#')
			continue;

		strncpy(cmd, trimmed_line, sizeof(cmd) - 1);
		global->data_arg = strtok(NULL, " \t\n");

		execute_cmd(cmd, line_number);
	}
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

	global = malloc(sizeof(global_t));
	if (global == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global->data_arg = NULL;
	global->file_ptr = NULL;
	global->stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit_failure(global);
	}

	file = argv[1];

	file_reader(file);

	free_stack(global->stack);
	if (global->file_ptr)
		fclose(global->file_ptr);
	free(global);

	return (0);
}
