#include "lib/tests/macros.h"
#include "lib/asserts.h"

Test(basic_test, test1)
{
    cr_assert(1 == 1);
}

Test(basic_test, test2)
{
    cr_assert(1 == 2);
}

Test(string, test1)
{
    cr_assert_str_eq("Hello", "Hello");
}

Test(string, test2)
{
    cr_assert_str_neq("Hello", "Hello");
}