#include "monty.h"

/**
 * execute - finds the function matching the opcode
 * @h: pointer to dll
 * @line: command line
 * @line_number: line number of the command line in the file
 */
void execute(stack_t **h, char *line, unsigned int line_number)
{
    instruction_t instr[] = {
        {"pall", pall}, {"add", _add}, {"sub", _sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pint", pint}, {"pchar", pchar}, {"pop", pop}, {"rotl", rotl}, {"rotr", rotr}, {"stack", stack}, {"queue", queue}, {"nop", nop}, {"swap", swap}, {NULL, NULL}};
    int i;
    char *start_c;

    start_c = skip_spaces(line);
    if (start_c == NULL)
        return;
    if (_strncmp(start_c, "push", _strlen("push")) == 0)
    {
        push(h, line, line_number);
        return;
    }

    for (i = 0; instr[i].opcode; ++i)
    {
        if (_strncmp(start_c, instr[i].opcode, _strlen(instr[i].opcode)) == 0)
        {
            free(line);
            (instr[i].f)(h, line_number);
            return;
        }
    }
    /*Maybe change for buffer.*/
    printf("L%d: unknown instruction ", line_number);
    while (*start_c && (*start_c != ' ' && *start_c != '\t'))
        putchar(*start_c++);
    putchar('\n');
    free(line);
    free_stack(*h);
    *h = NULL;
    exit(EXIT_FAILURE);
}

/**
 * get_argument - return the arguments for calulations
 * @h: pointer to dll
 * @opcode: opcode string
 * @l: line number
 * Return: the argument
 */
int get_argument(stack_t **h, char *opcode, unsigned int l)
{
    stack_t *node;
    int tmp;

    if (_strcmp(flag, "stack") == 0)
    {
        node = pop_s(h);
    }
    else
    {
        node = dequeue(h);
    }
    if (node == NULL)
    {
        printf("L%d: can't %s, %s too short\n", l, opcode, flag);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }
    tmp = node->n;
    free(node);
    return (tmp);
}
