#include "lib/tests/memory.h"
#include "lib/memory/datas.h"
#include <stdio.h>

void criterion_setup_memory(int return_leak_allowed)
{
    set_memory_leak_checking(1);
}

static void print_leaks(memory_leak_list **leaks)
{
    memory_leak_list *tmp = *leaks;

    while (tmp) {
        struct memory_leak *leak = tmp->data;
        printf("Memory leak of %ld blocks at %p allocated by the function %s in %s:%d\n", leak->block_size, leak->ptr, leak->function_name, leak->file, leak->line);
        tmp = tmp->next;
    }
}

static int get_leaks_count(memory_leak_list **leaks)
{
    int count = 0;
    memory_leak_list *tmp = *leaks;

    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

static void check_leaks()
{
    memory_leak_list **leaks = get_leaks();

    if (get_leaks_count(leaks) > 0) {
        print_leaks(leaks);
    }
}

void criterion_teardown_memory(int return_leak_allowed)
{
    check_leaks();
    set_memory_leak_checking(0);
}