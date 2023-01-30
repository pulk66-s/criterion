#ifndef __CRITERION_LIB_TESTS_MACRO_H__
    #define __CRITERION_LIB_TESTS_MACRO_H__
    
    #include "lib/tests/tests.h"

    #define Test(group, name) \
        void name(void); \
        static void __attribute__((constructor)) __##name(void) \
        { \
            criterion_register_test(#group, #name, name); \
        } \
        void name(void)


#endif