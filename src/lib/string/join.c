#include "join.h"
#include <stdlib.h>
#include <string.h>

char *join(char **strs, char *sep)
{
    size_t size = 0;
    size_t sep_size = strlen(sep);
    char *joined = NULL;

    for (size_t i = 0; strs[i]; i++) {
        size += strlen(strs[i]);
        if (strs[i + 1])
            size += sep_size;
    }
    joined = malloc(size + 1);
    memset(joined, 0, size + 1);
    for (size_t i = 0; strs[i]; i++) {
        strcat(joined, strs[i]);
        if (strs[i + 1])
            strcat(joined, sep);
    }
    return joined;
}