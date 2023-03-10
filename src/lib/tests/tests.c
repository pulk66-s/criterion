#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types/tests.h"
#include "lib/env/results.h"
#include "lib/asserts/io.h"

static test_list **tests = NULL;
static struct test *current_test = NULL;

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
        .success = -1
    });
}

void launch_tests()
{
    for (test_list *tmp = *tests; tmp; tmp = tmp->next) {
        clear_output_buffer();
        clear_error_buffer();
        replace_stdout();
        replace_stderr();
        current_test = tmp->data;
        current_test->func();
        if (current_test->success) {
            criterion_success();
        } else {
            criterion_failure();  
        }
        restore_stdout();
        restore_stderr();
    }
}

struct test *get_current_test()
{
    return current_test;
}

void clear_tests()
{
    free_tests(tests);
    free(tests);
}

void current_test_set_success(int success)
{
    if (current_test->success != 0)
        current_test->success = success;
}

test_list **criterion_get_tests()
{
    return tests;
}