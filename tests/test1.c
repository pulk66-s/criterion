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
