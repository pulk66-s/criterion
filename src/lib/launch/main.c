#include "lib/env/results.h"
#include "lib/tests/macros.h"
#include "lib/tests/tests.h"
#include <stdio.h>

int main(void)
{
    launch_tests();
    struct criterion_tests_results results = criterion_get_results();
    printf("Passed: %d, Failed: %d, Total: %d", results.passed, results.failed, results.total);
    return 0;
}