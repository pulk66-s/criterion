#include "lib/memory/datas.h"
#include "types/memory_leak.h"
#include <stdio.h>

static int memory_leak_checking = 0;
static memory_leak_list **leaks = NULL;

static void reset_memory_leak_checking()
{
    if (leaks) {
        free_leaks(leaks);
        free(leaks);
    }
    leaks = malloc(sizeof(struct memory_leak *));
    *leaks = NULL;
}

void set_memory_leak_checking(int value)
{
    memory_leak_checking = value;
    reset_memory_leak_checking();
}

int memory_leak_checking_is_enabled()
{
    return memory_leak_checking;
}

void add_memory_leak(struct memory_leak leak)
{
    if (!memory_leak_checking)
        return;
    add_leak(leaks, leak);
}

void delete_memory_leak(struct memory_leak leak)
{
    if (!memory_leak_checking)
        return;
    delete_leak(leaks, leak);
}

struct memory_leak *get_leak_by_ptr(void *ptr)
{
    if (!memory_leak_checking)
        return NULL;
    return get_memory_leak_by_ptr(leaks, ptr);
}

memory_leak_list **get_leaks()
{
    if (!memory_leak_checking)
        return NULL;
    return leaks;
}