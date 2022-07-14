#include "monty.h"

/*functions related to swapping and rotating elements*/

/**
 * swap - swap the values of the top and last elements
 * @h: head of the dll
 * @l: line number
 * opcode: swap
 */
void swap(stack_t **h, unsigned int l)
{
    int value0;

    if (!h || !*h)
    {
        printf("L%d: can't swap, %s too short\n", l, flag);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }

    value0 = (*h)->n;

    if ((*h)->next == NULL)
    {
        printf("L%d: can't swap, %s too short\n", l, flag);
        free_stack(*h);
        exit(EXIT_FAILURE);
    }

    (*h)->n = ((*h)->next)->n;
    ((*h)->next)->n = value0;
}

/**
 * rotl - the top element of the stack moves to the back
 * @h: head of the dll
 * @l: line number
 * opcode: rotl
 */
void rotl(stack_t **h, unsigned int l)
{
    stack_t *node, *tmp;

    (void)l;

    if (!h || !*h)
        return;
    if (!(*h)->next)
        return; /*one element in the stack*/

    node = pop_s(h);
    node->next = NULL;

    tmp = *h;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
    node->prev = tmp;
}

/**
 * rotr - the last element of the stack moves on top
 * @h: pointer to dll
 * @l: line number
 * opcode: rotr
 */
void rotr(stack_t **h, unsigned int l)
{
    stack_t *node;

    (void)l;

    if (!h || !*h)
        return;
    if (!(*h)->next)
        return; /*one element in the stack*/

    node = dequeue(h);
    node->prev = NULL;

    node->next = *h;
    (*h)->prev = node;
    *h = node;
}
