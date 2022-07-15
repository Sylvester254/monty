#include "monty.h"

/**
 * _push - adds an element to the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
stack_t *element = malloc(sizeof(stack_t));
char *opcode;
int num;

if (!element)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
opcode = strtok(NULL, "\n\t\r ");
if (opcode == NULL || stack == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
num = interpreter(opcode, line_number);
element->n = num;
element->prev = NULL;
element->next = *stack;
if (element->next != NULL)
(element->next)->prev = element;
*stack = element;
}
