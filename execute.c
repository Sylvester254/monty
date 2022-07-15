#include "monty.h"

/**
 * get_po - function that checks opcodes against valid opcodes.
 * @stack: double pointer to head of stack.
 * @op: pointer to opcode to check.
 * @line_number: script line number.
 *
 * Return: No return
 **/
void get_po(stack_t **stack, char *op, unsigned int line_number)
{
int i = 0;
instruction_t valid_opcodes[] = {
{"push", _push}, {"pchar", _pchar},
{"pall", _pall}, {"pstr", _pstr},
{"pint", _pint}, {"rotl", _rotl},
{"pop", _pop}, {"rotr", _rotr},
{"swap", _swap}, {"queue", _queue},
{"add", _add}, {"stack", _stack},
{"nop", _nop},
{"sub", _sub},
{"div", _div},
{"mul", _mul},
{"mod", _mod},
{NULL, NULL}
};

for (i = 0; valid_opcodes[i].opcode; i++)
{
if (strcmp(op, valid_opcodes[i].opcode) == 0)
{
valid_opcodes[i].f(stack, line_number);
return;
}
}
if (strlen(op) != 0 && op[0] != '#')
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
exit(EXIT_FAILURE);
}
}
