#ifndef __CRITERION_LIB_MEMORY_DATAS_H__
    #define __CRITERION_LIB_MEMORY_DATAS_H__

    #include "types/memory_leak.h"

void set_memory_leak_checking(int enabled);
int memory_leak_checking_is_enabled(void);
void add_memory_leak(struct memory_leak leak);
void delete_memory_leak(struct memory_leak leak);
struct memory_leak *get_leak_by_ptr(void *ptr);
memory_leak_list **get_leaks();

#endif