#include "criterion.h"
#include "libc.h"

Test(strcmp, basic_compare)
{
    cr_assert_eq(my_strcmp("Hello", "Hello"), 0);
}

Test(strcmp, basic_compare2)
{
    cr_assert_eq(my_strcmp("Hello", "Hello2"), -'2');
}

Test(strcmp, basic_compare3)
{
    cr_assert_eq(my_strcmp("Hello2", "Hello"), '2');
}

Test(strncmp, basic_compare)
{
    cr_assert_eq(my_strncmp("Hello", "Hello", 5), 0);
}

Test(strncmp, basic_compare2)
{
    cr_assert_eq(my_strncmp("Hello", "Hello2", 5), -'2');
}

Test(strncmp, basic_compare3)
{
    cr_assert_eq(my_strncmp("Hello2", "Hello", 4), 0);
}