#include "monty.h"

/* these functions are used to print all or an element of the linked list.
 * they correspond to the opcode in the description
 */

/**
 * pall - print all the elements in a dll as numbers
 * @head: pointer to dll
`* @l: line number
 * opcode: pall
 */
void pall(stack_t **head, unsigned int l)
{
    stack_t *h;
    (void)l;

    if (!head)
        return;
    h = *head;
    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

/**
 * pstr - print all the elements in a dll as chars
 * @head: pointer to dll
 * @l: line number
 * opcode: pstr
 */
void pstr(stack_t **head, unsigned int l)
{
    stack_t *h;
    (void)l;

    if (!head || !*head)
        puts("");

    h = *head;
    while (h != NULL && h->n > 0 && h->n < 127)
    {
        printf("%c\n", h->n);
        h = h->next;
    }
}

/**
 * pint - pick the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pchar
 */
void pint(stack_t **h, unsigned int l)
{

    if (!h || !*h)
    {
        printf("L%d: can't pint, %s empty\n", l, flag);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*h)->n);
}

/**
 * pchar - pick the top of the stack
 * @h: pointer to dll
 * @l: line number
 * opcode: pchar
 */
void pchar(stack_t **h, unsigned int l)
{
    int value;

    if (!h || !*h)
    {
        printf("L%d: can't pchar, %s empty\n", l, flag);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }

    value = (*h)->n;
    if (value < 0 || value > 127)
    {
        printf("L%d: can't pchar, value out of range\n", l);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }
    else
        printf("%c\n", value);
}
