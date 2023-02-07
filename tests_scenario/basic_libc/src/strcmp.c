#include "libc.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
        n--;
    }
    return n ? *s1 - *s2 : 0;
}
