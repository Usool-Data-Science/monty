#include <stdio.h>
#include "monty.h"

/**
  * token_counter - Counts the number of token in a word.
  * @word: The string to tokenize
  * Return: Count of tokens.
  */
int token_counter(char *word)
{
	int count = 0;
	char *token = NULL;
	char *delim = " \t\n";

	if (word == NULL)
		return (0);
	token = strtok(word, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	return (count);
}

/**
  * tokenizer - Tokenize only 2 commands
  * @command: The string command
  * Return: The tokenized strings.
  *
  * Description: To be used only when the
  * lists->num_token is equals to 2.
  */
token *tokenizer(char *command)
{
	char *tokens, *delim = " \t\n";
	token *new_token = (token *)malloc(sizeof(token));

	tokens = strtok(command, delim);
	if (tokens != NULL)
		new_token->opcode = strdup(tokens);
	tokens = strtok(NULL, delim);
	if (tokens != NULL)
		new_token->arg = strdup(tokens);

	return (new_token);
}

/**
  * file_reader - Store each line of command from file into a list
  * @file: The file to read.
  *
  * Return: The list of arguments.
  */
data_arg *file_reader(FILE *file)
{
	int counter = 0, line_no = 0, buffer_size = 256;
	data_arg *lists = NULL, *temp = NULL;
	char *buffer = (char *)malloc(buffer_size);
	char *buffer_words;
	data_arg *new_lists = (data_arg *)malloc(sizeof(data_arg));

	if (new_lists == NULL || buffer == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		perror("Error: File %s not found\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, buffer_size, file) != NULL)
	{
		buffer_words = strdup(buffer);
		line_no++;
		/*check if num_token == 2 */
		new_lists->command = tokenizer(buffer);
		new_lists->line_number = line_no;
		new_lists->num_token = token_counter(buffer_words);
		new_lists->next = NULL;
		/* Add new_list to all the command lists */
		if (lists == NULL)
			lists = new_lists;
		else
		{
			temp->next = new_lists;
			temp = temp->next;
		}
		printf("L%d attached %d tokens with opcode:%s and arg: %s to node successfully\n",
				new_lists->line_number,
				new_lists->num_token,
				new_lists->command->opcode,
				new_lists->command->arg);
	}
	temp = lists;
	while (temp != NULL)
	{
		counter++;
		lists = lists->next;
	}
	printf("Node Count: %d\n", counter);
	return (lists);
}
