#ifndef __CRITERION_LIB_TESTS_REGISTER_H__
    #define __CRITERION_LIB_TESTS_REGISTER_H__

void criterion_register_test(const char *group, const char *name, void (*func)());
void launch_tests();

#endif