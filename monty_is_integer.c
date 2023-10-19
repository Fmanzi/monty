#include "monty.h"

int is_integer(char *str)
{
        int i;

    if (str == NULL || *str == '\0')
        return 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue; /* Skip the sign character*/
        if (str[i] < '0' || str[i] > '9')
            return 0; /* Not a valid integer*/
    }
    return 1; /* It's a valid integer*/
}
