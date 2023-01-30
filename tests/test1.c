#include "lib/tests/macros.h"
#include "lib/asserts.h"
#include <stdio.h>

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

Test(output, stdout)
{
    printf("Hello");
    assert_stdout("Hello");
}

Test(output, stdout2)
{
    printf("Hello2");
    assert_stdout("Hello2");
}

Test(output, stderr)
{
    fprintf(stderr, "Hello");
    assert_stderr("Hello");
}

Test(output, stderr2)
{
    fprintf(stderr, "Hello2");
    assert_stderr("Hello");
}