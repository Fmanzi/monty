#include "monty.h"

void push(stack_t **stack, unsigned int value)
{
    stack_t *new_node;

    if (!stack)
    {
        /* Handle error: no stack provided */
        fprintf(stderr, "Error: no stack provided\n");
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        /* Handle error: malloc failed */
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}
