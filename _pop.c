#include "monty.h"

/**
 * _pop - function that removes the top element of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * If the stack is empty, print the error message,
 * L<line_number>: can't pop an empty stack, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 *
 * Return: No return.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popped;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	popped  = *stack;
	(*stack) = (*stack)->next;
	free(popped);
}
