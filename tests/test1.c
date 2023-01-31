#include "lib/tests/macros.h"
#include "lib/asserts.h"
#include "lib/memory/malloc.h"
#include "lib/memory/free.h"
#include <stdio.h>
#include <string.h>

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

Test(multiple, basic1)
{
    cr_assert(1 == 1);
    cr_assert(1 == 2);
    cr_assert(1 == 1);
}

void memory_leak_func(const char *str)
{
    char *ptr = malloc(sizeof(char) * 10);
    free(ptr);
}

void memory_leak_func_2(const char *str)
{
    char *ptr = malloc(sizeof(char) * 10);
}

void *return_ptr(const char *str)
{
    char *ptr = malloc(sizeof(char) * 10);
    return ptr;
}

MemoryTest(basic, memory_leak, memory_leak_func("Hello"));
MemoryTest(basic, memory_leak2, memory_leak_func_2("Hello2"));
// MemoryTest(basic, memory_leak2, memory_leak_func("Hello2"));
