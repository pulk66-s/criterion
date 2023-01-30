#include "lib/env/results.h"

static struct criterion_tests_results results = {
    .passed = 0,
    .failed = 0,
    .total = 0
};

struct criterion_tests_results criterion_get_results(void)
{
    return results;
}

void success(void)
{
    ++results.passed;
    ++results.total;
}

void failure(void)
{
    ++results.failed;
    ++results.total;
}
