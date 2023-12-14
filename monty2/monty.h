#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
  */
typedef struct instructions_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct data_argument: A list of commands in the file
  * @command: The command one each line.
  * @line_number: The incrementing line number of the command.
  * @num_token: The count of token in a command.
  * @next: The next node of command.
  */
typedef struct data_argument
{
	char *command;
	unsigned int line_number;
	int num_token;
	struct data_argument *next;
} data_arg;

typedef struct token
{
	char *opcode;
	char *arg;
} token;

/* LIST OF FUNCTION PROTOTYES from functions.c file */
int token_counter(char *word);
token *tokenizer(char *command);
data_arg *file_reader(FILE *file);
void execute_command(stack_t **stack,
		unsigned int line_number,
		char *opcode,
		char *arg);

#endif /* MONTY_H */
