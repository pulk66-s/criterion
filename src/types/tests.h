#ifndef __CRITERION_TYPES_TESTS_H__
    #define __CRITERION_TYPES_TESTS_H__

    #include "types/linked_list.h"

typedef struct linked_list test_list;

struct test {
    char *name;
};

void add_test(test_list **tests, struct test test);
void dump_test(struct test test);
void dump_tests(test_list **tests);
void free_tests(test_list **tests);

#endif