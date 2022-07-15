#ifndef MONTY
#define MONTY

#define  _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_vars - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
**/
typedef struct global_vars
{
	stack_t **top;
	instruction_t **ops;
} glob_vars;

extern glob_vars globv;

/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

var_t var;

extern var_t var;

#define STACK 0
#define QUEUE 1

void stack_init(stack_t **head);
void free_all(void);
int file_reader(char *filename, stack_t **stack);
void get_po(stack_t **stack, char *op, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
int interpreter(char *num_string, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY */