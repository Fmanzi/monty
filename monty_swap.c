#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *first;
        stack_t *second;


    if (!stack || !*stack || !((*stack)->next))
    {
        /* Handle error: stack is too short */
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = first->next;

    /* Swap the top two elements */
    first->next = second->next;
    second->prev = first->prev;

    first->prev = second;
    second->next = first;

    *stack = second;
}
