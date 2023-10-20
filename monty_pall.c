#include "monty.h"

/**
 * pall - Prints all elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
