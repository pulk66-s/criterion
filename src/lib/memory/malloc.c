#include <stdlib.h>
#include <string.h>
#include "lib/memory/datas.h"

void *my_malloc(size_t size, const char *file, size_t line, const char *func)
{
    void *ptr = malloc(size);
    if (memory_leak_checking_is_enabled()) {
        add_memory_leak((struct memory_leak) {
            .block_size = size,
            .file = strdup(file),
            .line = line,
            .function_name = strdup(func),
            .ptr = ptr
        });
    }
    return ptr;
}