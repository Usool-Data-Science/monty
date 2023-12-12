#include "monty.h"

int execute_cmd(char *line)
{
	/*
		include a loop that checks if the cmd is a monty command
		if its not, handle error and return 0
		else return 1 for success
		if it is parse it to the function that handles the command
	*/
}

int file_reader(const char *file)
{
	/*
		includes a loop that reads from filename
		line by line
		each line would trimmed for white spaces
		pass the pointer to line to execute_cmd function
		if its not empty after trimming
	*/
	char *line;
	execute_cmd(line);
}

/**
 * main - entry point for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: SUCCESS on success FAILURE on failure*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	const char *file = argv[1];

	file_reader(file);

	if (file_reader)
		return (EXIT_SUCCESS);
}