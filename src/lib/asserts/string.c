#include "lib/tests/tests.h"
#include <string.h>

void cr_assert_str_eq(char *a, char *b)
{
    struct test *test = get_current_test();
    test->success = strcmp(a, b) == 0;
}

void cr_assert_str_neq(char *a, char *b)
{
    struct test *test = get_current_test();
    test->success = strcmp(a, b) != 0;
}