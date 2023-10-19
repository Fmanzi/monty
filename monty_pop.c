#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *current;
    if (!stack || !*stack)
    {
        /* Handle error: stack is empty */
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *stack;

    if (current->next)
        current->next->prev = NULL;

    *stack = current->next;
    free(current);
}
