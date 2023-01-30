#include "lib/env/results.h"
#include <stdio.h>

int main(void)
{
    success();
    failure();
    struct criterion_tests_results results = criterion_get_results();
    printf("Passed: %d, Failed: %d, Total: %d", results.passed, results.failed, results.total);
    return 0;
}