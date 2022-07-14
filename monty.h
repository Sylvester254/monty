#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*extern variable, stack or queue*/

extern char *flag;

#define LINE_LENGTH 32

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

/*basic functions related to doubly linked list*/
stack_t *add_node(stack_t **head, const int n);
void free_stack(stack_t *head);
stack_t *pop_s(stack_t **head);
stack_t *dequeue(stack_t **head);

/*functions to print the stack or queue*/
void pall(stack_t **h, unsigned int l);
void pstr(stack_t **h, unsigned int l);
void pchar(stack_t **h, unsigned int l);
void pint(stack_t **h, unsigned int l);

/*in push-pop*/
void pop(stack_t **h, unsigned int l);
void push(stack_t **h, char *line, unsigned int l);

/*in move_elements_functions*/
void swap(stack_t **h, unsigned int l);
void rotl(stack_t **h, unsigned int l);
void rotr(stack_t **h, unsigned int l);

/*in calc*/
int get_argument(stack_t **h, char *opcode, unsigned int l);
void _add(stack_t **h, unsigned int l);
void _sub(stack_t **h, unsigned int l);
void _div(stack_t **h, unsigned int l);
void _mul(stack_t **h, unsigned int l);
void _mod(stack_t **h, unsigned int l);

/*in nop-queue*/
void stack(stack_t **h, unsigned int l);
void queue(stack_t **h, unsigned int l);
void nop(stack_t **h, unsigned int l);

/*in atoi*/
char *skip_spaces(char *s);
char *reach_number(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);

/*in exec*/
void execute(stack_t **h, char *line, unsigned int line_number);

/*in main*/
int main(int ac, char **av);

#endif
