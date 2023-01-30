#include "lib/asserts/asserts.h"
#include "lib/tests/tests.h"

void cr_assert(int condition)
{
    struct test *test = get_current_test();
    test->success = condition;
}