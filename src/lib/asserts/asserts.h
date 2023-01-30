#ifndef __CRITERION_LIB_ASSERTS_ASSERTS_H__
    #define __CRITERION_LIB_ASSERTS_ASSERTS_H__

void cr_assert(int condition);
void cr_assert_eq(int a, int b);
void cr_assert_neq(int a, int b);
void cr_assert_lt(int a, int b);
void cr_assert_gt(int a, int b);
void cr_assert_lte(int a, int b);
void cr_assert_gte(int a, int b);

#endif