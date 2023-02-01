#ifndef __CRITERION_LIB_TESTS_MACRO_H__
    #define __CRITERION_LIB_TESTS_MACRO_H__
    
    #include "lib/tests/tests.h"
    #include "lib/tests/memory.h"

    #define Test(group, name) \
        void name##group(void); \
        static void __attribute__((constructor)) __##name##group(void) \
        { \
            criterion_register_test(#group, #name, name##group); \
        } \
        void name##group(void)

    #define MemoryTest(group, name, call) \
        static void __attribute__((constructor)) __##name##group(void) \
        { \
            criterion_setup_memory(); \
            call; \
            criterion_teardown_memory(0); \
        } \

    #define MemoryTestLeakAllowed(group, name, call, leak_allowed) \
        static void __attribute__((constructor)) __##name##group(void) \
        { \
            criterion_setup_memory(); \
            call; \
            criterion_teardown_memory(leak_allowed); \
        } \

#endif