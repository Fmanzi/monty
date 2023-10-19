#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
};

/**
 * get_instruction - Get the function associated with an opcode
 * @opcode: The opcode to look up
 *
 * Return: A pointer to the function, or NULL if the opcode is not found
 */
instruction_t *get_instruction(char *opcode)
{
    int i = 0;
    while (instructions[i].opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
            return &instructions[i];
        i++;
    }
    return NULL;
}
