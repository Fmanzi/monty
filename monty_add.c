#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
        int result;
    if (!stack || !*stack || !((*stack)->next))
    {
        /* Handle error: stack is too short */
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->n + ((*stack)->next)->n;
    pop(stack, line_number); /* Remove the top element*/
    (*stack)->n = result; /* Store the result in the new top element*/
}
