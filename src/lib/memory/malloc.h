#ifndef __CRITERION_LIB_MEMORY_MALLOC_H__
    #define __CRITERION_LIB_MEMORY_MALLOC_H__

    #include <stdlib.h>

void *my_malloc(size_t size, const char *file, size_t line, const char *func);

    #define malloc(x) my_malloc(x, __FILE__, __LINE__, __FUNCTION__)

#endif