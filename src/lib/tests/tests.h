#ifndef __CRITERION_LIB_TESTS_REGISTER_H__
    #define __CRITERION_LIB_TESTS_REGISTER_H__

    #include "types/tests.h"

void criterion_register_test(const char *group, const char *name, void (*func)());
void launch_tests();
struct test *get_current_test();

#endif