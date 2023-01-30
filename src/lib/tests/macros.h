#ifndef __CRITERION_LIB_TESTS_MACRO_H__
    #define __CRITERION_LIB_TESTS_MACRO_H__
    
    #include "lib/tests/tests.h"

    #define Test(group, name) \
        void name##group(void); \
        static void __attribute__((constructor)) __##name##group(void) \
        { \
            criterion_register_test(#group, #name, name##group); \
        } \
        void name##group(void)

#endif