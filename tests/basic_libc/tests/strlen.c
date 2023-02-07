#include "criterion.h"
#include "libc.h"

Test(strlen, basic_size)
{
    cr_assert_eq(my_strlen("Hello"), 5);
}

Test(strlen, empty_string)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(strlen, null_string)
{
    cr_assert_eq(my_strlen(NULL), 0);
}
