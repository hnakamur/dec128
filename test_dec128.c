#include <stdio.h>
#include "dec128.h"
#include "CUnit/Basic.h"

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
    return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
    return 0;
}

void test_isSignMinus(void)
{
    dec128 d;

    d128_setZero(&d);
    CU_ASSERT_FALSE(d128_isSignMinus(&d));

    d128_negate(&d, &d);
    CU_ASSERT_TRUE(d128_isSignMinus(&d));
}

void test_isZero(void)
{
    dec128 d;

    d128_setZero(&d);
    CU_ASSERT_TRUE(d128_isZero(&d));
}

void test_isFinite(void)
{
    dec128 d;

    d128_setZero(&d);
    CU_ASSERT_TRUE(d128_isFinite(&d));

    d128_negate(&d, &d);
    CU_ASSERT_TRUE(d128_isFinite(&d));

    d128_setInfinite(&d);
    CU_ASSERT_FALSE(d128_isFinite(&d));

    d128_negate(&d, &d);
    CU_ASSERT_FALSE(d128_isFinite(&d));

    d128_setSNaN(&d);
    CU_ASSERT_FALSE(d128_isFinite(&d));

    d128_setQNaN(&d);
    CU_ASSERT_FALSE(d128_isFinite(&d));
}

void test_isInfinite(void)
{
    dec128 d;

    d128_setInfinite(&d);
    CU_ASSERT_TRUE(d128_isInfinite(&d) && !d128_isSignMinus(&d));

    d128_negate(&d, &d);
    CU_ASSERT_TRUE(d128_isInfinite(&d) && d128_isSignMinus(&d));
}

void test_isSNaN(void)
{
    dec128 d;

    d128_setSNaN(&d);
    CU_ASSERT_TRUE(d128_isSNaN(&d));
}

void test_isQNaN(void)
{
    dec128 d;

    d128_setQNaN(&d);
    CU_ASSERT_TRUE(d128_isQNaN(&d));
}

void test_exponent(void)
{
    dec128 d;

    d128_setZero(&d);
    CU_ASSERT_EQUAL(d128_exponent(&d), 0);
}


/* The main() function for setting up and running the tests.
 *  * Returns a CUE_SUCCESS on successful running, another
 *   * CUnit error code on failure.
 *    */
int main()
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

#define add_test(name, func) (NULL == CU_add_test(pSuite, name, func))
    if (add_test("test of d128_isSignMinus", test_isSignMinus) ||
        add_test("test of d128_isZero", test_isZero) ||
        add_test("test of d128_isFinite", test_isFinite) ||
        add_test("test of d128_isInfinite", test_isInfinite) ||
        add_test("test of d128_isSNaN", test_isSNaN) ||
        add_test("test of d128_isQNaN", test_isQNaN) ||
        add_test("test of d128_exponent", test_exponent)
    ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

