#include <stdlib.h>
#include "lib/memory/datas.h"

void my_free(void *ptr)
{
    if (memory_leak_checking_is_enabled()) {
        struct memory_leak *leak = get_leak_by_ptr(ptr);
        delete_memory_leak(*leak);
    }
    free(ptr);
}