#include <assert.h>
#include "dec128.h"

inline bool d128_isSignMinus(dec128 *number)
{
    return number->lsu[0] & 0x80000000;
}

inline bool d128_isNaN(dec128 *number)
{
    return (number->lsu[0] & 0x7C000000) == 0x7C000000;
}

inline bool d128_isSNaN(dec128 *number)
{
    return (number->lsu[0] & 0x7D000000) == 0x7D000000;
}

inline bool d128_isQNaN(dec128 *number)
{
    return (number->lsu[0] & 0x7D000000) == 0x7C000000;
}

inline bool d128_isInfinite(dec128 *number)
{
    return (number->lsu[0] & 0x7C000000) == 0x78000000;
}

inline bool d128_isFinite(dec128 *number)
{
    return !d128_isInfinite(number) && !d128_isNaN(number);
}

inline bool d128_isZero(dec128 *number)
{
    /* FIXME: implement. */
    return false;
}

void d128_setZero(dec128 *number)
{
    number->lsu[0] = number->lsu[1] = number->lsu[2] = number->lsu[3] = 0;
}

void d128_setInfinite(dec128 *number)
{
    number->lsu[0] = 0x78000000;
    number->lsu[1] = number->lsu[2] = number->lsu[3] = 0;
}

void d128_setSNaN(dec128 *number)
{
    number->lsu[0] = 0x7D000000;
    number->lsu[1] = number->lsu[2] = number->lsu[3] = 0;
}

void d128_setQNaN(dec128 *number)
{
    number->lsu[0] = 0x7C000000;
    number->lsu[1] = number->lsu[2] = number->lsu[3] = 0;
}

int32_t d128_exponent(dec128 *number)
{
    assert(d128_isFinite(number));

    /* FIXME: implement. */
    return -1;
}

void d128_copy(dec128 *result, const dec128 *number)
{
    if (result != number) {
        *result = *number;
    }
}

void d128_negate(dec128 *result, const dec128 *number)
{
    if (result != number) {
        *result = *number;
    }
    result->lsu[0] ^= 0x80000000;
}

void d128_abs(dec128 *result, const dec128 *number)
{
    if (result != number) {
        *result = *number;
    }
    result->lsu[0] &= 0x7FFFFFFF;
}
