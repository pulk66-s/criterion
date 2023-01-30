#include "types/tests.h"
#include <stdlib.h>
#include <stdio.h>

void add_test(test_list **tests, struct test test)
{
    struct test *new_test = malloc(sizeof(struct test));
    *new_test = test;
    linked_list_add(tests, new_test);
}

void dump_test(struct test test)
{
    printf("Test: %s\n", test.name);
}

static void dump_test_ptr(void *test)
{
    dump_test(*(struct test *)test);
}

void dump_tests(test_list **tests)
{
    if (!tests)
        return;
    linked_list_foreach(tests, &dump_test_ptr);
}

static void free_test(void *ptr)
{
    struct test *test = ptr;

    free(test->name);
}

void free_tests(test_list **tests)
{
    linked_list_foreach(tests, free_test);
    linked_list_free(tests);
}