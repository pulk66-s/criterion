#include "lib/tests/tests.h"
#include <string.h>

void cr_assert_str_eq(char *a, char *b)
{
    current_test_set_success(strcmp(a, b) == 0);
}

void cr_assert_str_neq(char *a, char *b)
{
    current_test_set_success(strcmp(a, b) != 0);
}