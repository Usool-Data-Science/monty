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
extern FILE *file_ptr;

#define LENGTH 1020

int file_reader(char *file);
int execute_cmd(char *cmd, unsigned int line_number);

int convertToInt(char *toInt, unsigned int line_number, char *command);

size_t stack_len(const stack_t *h);
void free_stack(stack_t *stack);
void exec_push(stack_t **stack, unsigned int line_number);
void exec_pall(stack_t **stack, unsigned int line_number);
void exec_pint(stack_t **stack, unsigned int line_number);
void exec_pop(stack_t **stack, unsigned int line_number);
void exec_swap(stack_t **stack, unsigned int line_number);
void exec_add(stack_t **stack, unsigned int line_number);
void exec_nop(stack_t **stack, unsigned int line_number);
void exec_sub(stack_t **stack, unsigned int line_number);
void exec_div(stack_t **stack, unsigned int line_number);
void exec_mul(stack_t **stack, unsigned int line_number);
void exec_mod(stack_t **stack, unsigned int line_number);
void exec_pchar(stack_t **stack, unsigned int line_number);
void exec_pstr(stack_t **stack, unsigned int line_number);

#endif /* MAIN_H */
