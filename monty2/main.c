#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

static stack_t **result_stack;
/**
  * execute_command - Executes sets of instruction codes.
  * @stack: The parent stack to store results.
  * @line_number: The number of current line.
  * @opcode: Operation code to use on operands.
  * @arg: The operand.
  */
void execute_command(stack_t **stack, unsigned int line_number,
		char *opcode, char *arg)
{
	(void)stack;
	printf("Line No: %d has opcode: %s and argument: %s\n",
			line_number, opcode, arg);
}

/**
  * main - entry point
  * @argc: Argumen counts.
  * @argv: Argument variable array.
  *
  * Return: 0 on successful execution.
  */
int main(int argc, char *argv[])
{
	FILE *file;
	//token *line_command = NULL;
	data_arg *command_list = NULL;

	/* 1. Check the command size */
	if (argc != 2)
	{
		perror("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* 2. Open the file and read the commands. */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* 3. Read each line of the file into a linked list*/
	command_list = file_reader(file);
	/* 4. Iterate over each command in the node and execute it*/
	while (command_list != NULL)
	{
		if (command_list->num_token != 2)
		{
			perror("Error: Token < 2\n");
			exit(EXIT_FAILURE);
		}
		/* Check number of args per line */
		execute_command(result_stack,
				command_list->line_number,
				(command_list->command)->opcode,
				(command_list->command)->arg);
		command_list = command_list->next;
	}
	/* 5. Return after successful execution */
	return (0);
}
