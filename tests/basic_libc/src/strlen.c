#include "libc.h"

size_t my_strlen(const char *s)
{
    size_t len = 0;

    if (!s)
        return len;
    while (s[len])
        len++;
    return len;
}