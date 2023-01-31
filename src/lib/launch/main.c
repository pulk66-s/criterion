#include "lib/env/results.h"
#include "lib/tests/macros.h"
#include "lib/tests/tests.h"
#include <stdio.h>
#include "lib/asserts/io.h"

static void print_details()
{
    test_list **tests = criterion_get_tests();

    for (test_list *tmp = *tests; tmp; tmp = tmp->next) {
        struct test *test = tmp->data;
        if (test->success == 0)
            printf("Test %s.%s is not passed\n", test->group, test->name);
    }
}

int main(void)
{
    launch_tests();
    struct criterion_tests_results results = criterion_get_results();
    printf("Passed: %d, Failed: %d, Total: %d\n", results.passed, results.failed, results.total);
    print_details();
    clear_tests();
    return 0;
}