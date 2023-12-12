#include "monty.h"


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

	const char *filename = argv[1];
	file_reader(filename);

	return (EXIT_SUCCESS);
}