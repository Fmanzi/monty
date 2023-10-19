#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack;
    char *line = NULL;
   /* size_t len = 0;*/
    unsigned int line_number = 1;

    stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        char *opcode = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");

        if (opcode)
        {
            instruction_t *instruction;
            if (arg && is_integer(arg))
                push(&stack, atoi(arg));

            instruction = get_instruction(opcode);
            if (instruction)
                instruction->f(&stack, line_number);
            else if (strcmp(opcode, "nop") == 0)
            {
                nop(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free(line);
                fclose(file);
                while (stack)
                {
                    stack_t *temp = stack;
                    stack = stack->next;
                    free(temp);
                }
                return (EXIT_FAILURE);
            }
        }
        line_number++;
    }

    free(line);
    fclose(file);
    while (stack)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return (0);
}
