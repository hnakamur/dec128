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

    // -7.50
    d128_setUnits(&d, 0xA2078000, 0x00000000, 0x00000000, 0x000003D0);
    cut_assert_equal_int(-2, d128_exponent(&d));

    // -7.50E+3
    d128_setUnits(&d, 0xA2084000, 0x00000000, 0x00000000, 0x000003D0);
    cut_assert_equal_int(3 - 2, d128_exponent(&d));

    // -750
    d128_setUnits(&d, 0xA2080000, 0x00000000, 0x00000000, 0x000003D0);
    cut_assert_equal_int(0, d128_exponent(&d));

    // -75.0
    d128_setUnits(&d, 0xA207C000, 0x00000000, 0x00000000, 0x000003D0);
    cut_assert_equal_int(-1, d128_exponent(&d));

    // -0.750
    d128_setUnits(&d, 0xA2074000, 0x00000000, 0x00000000, 0x000003D0);
    cut_assert_equal_int(-3, d128_exponent(&d));

    // 0
    d128_setZero(&d);
    cut_assert_equal_int(0, d128_exponent(&d));
}
