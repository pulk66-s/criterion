#ifndef __CRITERION_TYPES_MEMORY_LEAK_H__
    #define __CRITERION_TYPES_MEMORY_LEAK_H__

    #include "types/linked_list.h"
    #include <stdlib.h>

typedef struct linked_list memory_leak_list;

struct memory_leak {
    size_t block_size;
    char *file;
    int line;
    char *function_name;
    void *ptr;
};

void add_leak(memory_leak_list **leaks, struct memory_leak leak);
void dump_leak(struct memory_leak leak);
void dump_leaks(memory_leak_list **leaks);
void free_leaks(memory_leak_list **leaks);
void delete_leak(memory_leak_list **leaks, struct memory_leak leak);
struct memory_leak *get_memory_leak_by_ptr(memory_leak_list **leaks, void *ptr);

#endif