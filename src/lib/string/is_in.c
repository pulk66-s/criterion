#include "is_in.h"
#include <stdlib.h>

int is_in(char c, char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}