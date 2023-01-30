#ifndef __CRITERION_LIB_RESULTS_H__
    #define __CRITERION_LIB_RESULTS_H__

    #include "types/linked_list.h"

struct criterion_tests_results {
    unsigned int passed;
    unsigned int failed;
    unsigned int total;
};

struct criterion_tests_results criterion_get_results(void);
void success(void);
void failure(void);

#endif