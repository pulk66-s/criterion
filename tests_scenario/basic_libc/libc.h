#ifndef __CRITERION_TESTS_LIBC_H__
    #define __CRITERION_TESTS_LIBC_H__

    #include <stdlib.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);

#endif