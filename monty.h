#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *data_arg;

int file_reader(const char *file);
int execute_cmd(char *cmd, stack_t **stack, unsigned int line_number, char *file_arg)

int convertToInt(char *toInt, unsigned int line_number, char *command);

void exec_push(stack_t **stack, unsigned int line_number);
void exec_pall(stack_t **stack, unsigned int line_number);
void exec_pint(stack_t **stack, unsigned int line_number);
void exec_pop(stack_t **stack, unsigned int line_number);

#endif /* MAIN_H */
