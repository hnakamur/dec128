#include <stdio.h>
#include <cutter.h>
#include "dec128.h"

void test_isSignMinus(void)
{
    dec128 d;

    d128_setZero(&d);
    cut_assert_false(d128_isSignMinus(&d));

    d128_negate(&d, &d);
    cut_assert_true(d128_isSignMinus(&d));
}

void test_isZero(void)
{
    dec128 d;

    d128_setZero(&d);
    cut_assert_true(d128_isZero(&d));
}

void test_isFinite(void)
{
    dec128 d;

    d128_setZero(&d);
    cut_assert_true(d128_isFinite(&d));

    d128_negate(&d, &d);
    cut_assert_true(d128_isFinite(&d));

    d128_setInfinite(&d);
    cut_assert_false(d128_isFinite(&d));

    d128_negate(&d, &d);
    cut_assert_false(d128_isFinite(&d));

    d128_setSNaN(&d);
    cut_assert_false(d128_isFinite(&d));

    d128_setQNaN(&d);
    cut_assert_false(d128_isFinite(&d));
}

void test_isInfinite(void)
{
    dec128 d;

    d128_setInfinite(&d);
    cut_assert_true(d128_isInfinite(&d) && !d128_isSignMinus(&d));

    d128_negate(&d, &d);
    cut_assert_true(d128_isInfinite(&d) && d128_isSignMinus(&d));
}

void test_isSNaN(void)
{
    dec128 d;

    d128_setSNaN(&d);
    cut_assert_true(d128_isSNaN(&d));
}

void test_isQNaN(void)
{
    dec128 d;

    d128_setQNaN(&d);
    cut_assert_true(d128_isQNaN(&d));
}

void test_exponent(void)
{
    dec128 d;

    d128_setZero(&d);
    cut_assert_equal_int(d128_exponent(&d), 0);
}
