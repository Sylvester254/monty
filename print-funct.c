#include "monty.h"

/**
 * _pall - Prints stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * Return: No return.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
stack_t *element = *stack;

(void)(line_number);
while (element != NULL)
{
printf("%d\n", element->n);
element = element->next;
}
}

/**
 * _pstr - function that prints the string starting at top of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The integer stored at the top of the stack is treated as the ascii,
 * value of the character to be printed.
 * The string stops when either: the stack is over, the value of the,
 * element is 0 or the value of the element is not in the ascii table.
 * If the stack is empty, print only a new line.
 *
 * Return: No return.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);
	if (!(*stack))
	{
		printf("\n");
		return;
	}
	while (temp_variable)
	{
		if (isascii(temp_variable->n) && temp_variable->n != 0)
			putchar(temp_variable->n);
		else
			break;
		temp_variable = temp_variable->next;
	}
	putchar('\n');
}

/**
 * _pint - function that prints the value at the top of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Usage: pint .
 * If the stack is empty, print the error message,
 * L<line_number>: can't pint, stack empty, followed by a new line,
 * and exit with the status EXIT_FAILURE.
 *
 * Return: No return.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pchar - function that prints the char at the top of the stack.
 * @stack: double pointer to the head of stack
 * @line_number: script line number.
 *
 * The integer stored at the top of the stack is treated as the ascii,
 * value of the character to be printed.
 * If the value is not in the ascii table (man ascii) print the error,
 * message L<line_number>: can't pchar, value out of range, followed by,
 * a new line, and exit with the status EXIT_FAILURE.
 * If the stack is empty, print the error message:
 * L<line_number>: can't pchar, stack empty, followed by a new line, and,
 * exit with the status EXIT_FAILURE .
 *
 * Return: No return.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
