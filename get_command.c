#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_command(char *file_name, int line_no)
{
	int i;
	char buffer[256];
	char *result = NULL;

	// Open the document
	FILE *file = fopen(file_name, "r");
	if (file == NULL)
	{
		perror("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < line_no; i++)
	{
		if(fgets(buffer, sizeof(buffer), file) == NULL)
		{
			fprintf(stderr, "Line %d is not found\n", i);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	result = strdup(buffer);
	if (result == NULL)
	{
		perror("Can't allocate memory for result\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("Line %d: %s", i + 1, result);

	fclose(file);
	return (result);
}

int main(void)
{
	char *line = get_command("./bytecodes/000.m", 5);

	free(line);
	return (0);
}
