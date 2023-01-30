#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types/tests.h"

test_list **tests = NULL;

void criterion_register_test(const char *group, const char *name, void (*func)())
{
    if (!tests) {
        tests = malloc(sizeof(test_list *));
        *tests = NULL;
    }
    add_test(tests, (struct test) {
        .name = strdup(name),
        .group = strdup(group),
        .func = func
    });
}

void launch_tests()
{
    for (test_list *tmp = *tests; tmp; tmp = tmp->next) {
        struct test *test = tmp->data;
        test->func();
    }
}