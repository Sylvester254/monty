#include "monty.h"

/**
 * _add - function that adds the top two elements of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: add .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't swap, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, and the,
 * top element is removed, so that at the end:
 * The top element of the stack contains the result and the stack is one,
 * element shorter
 *
 * Return: No return.
 */
void _add(stack_t **stack, unsigned int line_number)
{
int temp_variable;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp_variable = (*stack)->n;
_pop(stack, line_number);
(*stack)->n += temp_variable;
}

/**
 * _sub - function that subtracts the top element of the stack from the,
 * second top element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: add .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't sub, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, so that,
 * at the end: The top element of the stack contains the result and the,
 * stack is one element shorter.
 *
 * Return: No return.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n -= temp_variable;
}

/**
 * _div - function that divides the second top element of the stack by,
 * the top element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: div .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't div, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, so that,
 * at the end: The top element of the stack contains the result and the,
 * stack is one element shorter.
 * If the top element of the stack is 0, print the error message,
 * L<line_number>: division by zero, followed by a new line, and exit,
 * with the status EXIT_FAILURE.
 *
 * Return: No return.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_variable = (*stack)->n;
	if (temp_variable == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
	(*stack)->n /= temp_variable;
}

/**
 * _mul - function that multiplies the second top element of the stack,
 * with the top element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: mul .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't mul, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, and the,
 * top element is removed, so that at the end: The top element of the,
 * stack contains the result and the stack is one element shorter.
 *
 * Return: No return.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n *= temp_variable;
}

/**
 * _mod - function that multiplies the second top element of the stack,
 * with the top element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: mod .
 * If the stack contains less than two elements, print the error message,
 * L<line_number>: can't mod, stack too short, followed by a new line,
 * and exit with the status EXIT_FAILURE .
 * The result is stored in the second top element of the stack, and the,
 * top element is removed, so that at the end: The top element of the,
 * stack contains the result and the stack is one element shorter.
 * If the top element of the stack is 0, print the error message,
 * L<line_number>: division by zero, followed by a new line, and exit,
 * with the status EXIT_FAILURE.
 *
 * Return: No return.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	if (temp_variable == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= temp_variable;
}
