#include "lib/asserts/asserts.h"
#include "lib/tests/tests.h"

void cr_assert(int condition)
{
    struct test *test = get_current_test();
    test->success = condition;
}

void cr_assert_eq(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a == b;
}

void cr_assert_neq(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a != b;
}

void cr_assert_lt(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a < b;
}

void cr_assert_gt(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a > b;
}

void cr_assert_lte(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a <= b;
}

void cr_assert_gte(int a, int b)
{
    struct test *test = get_current_test();
    test->success = a >= b;
}
