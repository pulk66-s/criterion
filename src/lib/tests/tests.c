#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types/tests.h"
#include "lib/env/results.h"

test_list **tests = NULL;
struct test *current_test = NULL;

void criterion_register_test(const char *group, const char *name, void (*func)())
{
    if (!tests) {
        tests = malloc(sizeof(test_list *));
        *tests = NULL;
    }
    add_test(tests, (struct test) {
        .name = strdup(name),
        .group = strdup(group),
        .func = func,
        .success = 0
    });
}

void launch_tests()
{
    for (test_list *tmp = *tests; tmp; tmp = tmp->next) {
        current_test = tmp->data;
        current_test->func();
        if (current_test->success) {
            criterion_success();
        } else {
            criterion_failure();  
        }
    }
}

struct test *get_current_test()
{
    return current_test;
}
