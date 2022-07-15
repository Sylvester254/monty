#include "monty.h"

/**
 * _nop - function that doesn't do anythin.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: nop .
 *
 * Return: No return.
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * _queue - onverts stacks to a queue.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number
 *
 * Return: No return.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
	var.queue = QUEUE;
}

/**
 * _stack - Converts a queue to a stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number
 *
 * Return: Void.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
	var.queue = QUEUE;
}
