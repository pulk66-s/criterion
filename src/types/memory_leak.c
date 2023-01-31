#include "types/memory_leak.h"
#include <stdio.h>

void add_leak(memory_leak_list **leaks, struct memory_leak leak)
{
    struct memory_leak *new_leak = malloc(sizeof(struct memory_leak));
    *new_leak = leak;
    linked_list_add(leaks, new_leak);
}

void dump_leak(struct memory_leak leak)
{
    printf("Leak: %zu bytes allocated in %s:%d in %s()\n", leak.block_size, leak.file, leak.line, leak.function_name);
}

static void dump_leak_ptr(void *leak)
{
    dump_leak(*(struct memory_leak *)leak);
}

void dump_leaks(memory_leak_list **leaks)
{
    if (!leaks)
        return;
    linked_list_foreach(leaks, &dump_leak_ptr);
}

static void free_leak(void *ptr)
{
    struct memory_leak *leak = ptr;

    free(leak->file);
    free(leak->function_name);
}

void free_leaks(memory_leak_list **leaks)
{
    linked_list_foreach(leaks, free_leak);
    linked_list_free(leaks);
}

static int delete_leak_condition(void *leak, void *to_delete)
{
    struct memory_leak *l = leak;
    struct memory_leak *d = to_delete;

    return (
        l->block_size == d->block_size
        && l->file == d->file
        && l->line == d->line
        && l->function_name == d->function_name
    );
}

void delete_leak(memory_leak_list **leaks, struct memory_leak leak)
{
    linked_list_delete(leaks, &leak, delete_leak_condition);
}

static int get_leak_by_ptr_condition(void *leak, void *ptr)
{
    struct memory_leak *l = leak;

    return l->ptr == ptr;
}

struct memory_leak *get_memory_leak_by_ptr(memory_leak_list **leaks, void *ptr)
{
    return linked_list_get(leaks, ptr, get_leak_by_ptr_condition);
}
