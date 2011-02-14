#include <assert.h>
#include "dec128.h"
#include "dec128Int.h"

const static dec128 ZERO = { 0x22080000, 0, 0, 0 };

static uint32_t d128_lead_digit(dec128 *number);

inline bool d128_isSignMinus(dec128 *number)
{
    return number->unit[0] & d128_mask32(0, 1, 0x1);
}

inline bool d128_isNaN(dec128 *number)
{
    return (number->unit[0] & d128_mask32(1, 5, 0x1F))
        == d128_mask32(1, 5, 0x1F);
}

inline bool d128_isSNaN(dec128 *number)
{
    return (number->unit[0] & d128_mask32(1, 6, 0x3F))
        == d128_mask32(1, 6, 0x3F);
}

inline bool d128_isQNaN(dec128 *number)
{
    return (number->unit[0] & d128_mask32(1, 6, 0x3F))
        == d128_mask32(1, 6, 0x3E);
}

inline bool d128_isInfinite(dec128 *number)
{
    return (number->unit[0] & d128_mask32(1, 5, 0x1F))
        == d128_mask32(1, 5, 0x1E);
}

inline bool d128_isFinite(dec128 *number)
{
    return !d128_isInfinite(number) && !d128_isNaN(number);
}

inline bool d128_isZero(dec128 *number)
{
    return d128_lead_digit(number) == 0 && (number->unit[0] & 0xFFF) == 0
        && number->unit[1] == 0 && number->unit[2] == 0
        && number->unit[3] == 0;
}

void d128_setUnits(dec128 *number, uint32_t u0, uint32_t u1, uint32_t u2,
    uint32_t u3)
{
    number->unit[0] = u0;
    number->unit[1] = u1;
    number->unit[2] = u2;
    number->unit[3] = u3;
}

void d128_setZero(dec128 *number)
{
    *number = ZERO;
}

void d128_setInfinite(dec128 *number)
{
    number->unit[0] = d128_mask32(1, 5, 0x1E);
    number->unit[1] = number->unit[2] = number->unit[3] = 0;
}

void d128_setSNaN(dec128 *number)
{
    number->unit[0] = d128_mask32(1, 6, 0x3F);
    number->unit[1] = number->unit[2] = number->unit[3] = 0;
}

void d128_setQNaN(dec128 *number)
{
    number->unit[0] = d128_mask32(1, 6, 0x3E);
    number->unit[1] = number->unit[2] = number->unit[3] = 0;
}

int32_t d128_exponent(dec128 *number)
{
    uint32_t u0;

    assert(d128_isFinite(number));

    u0 = number->unit[0];
    return (((u0 & d128_mask32(1, 2, 0x3)) == d128_mask32(1, 2, 0x3)
        ? (u0 & d128_mask32(3, 2, 0x3)) >> (d128_UNIT_BIT_WIDTH - 3 - 2 - 12)
        : (u0 & d128_mask32(1, 2, 0x3)) >> (d128_UNIT_BIT_WIDTH - 1 - 2 - 12))
        | (u0 & d128_mask32(6, 12, 0xFFF)) >> (d128_UNIT_BIT_WIDTH - 6 - 12))
        - d128_BIAS;
}

uint32_t d128_lead_digit(dec128 *number)
{
    uint32_t u0;

    assert(d128_isFinite(number));

    u0 = number->unit[0];
    return (u0 & d128_mask32(1, 2, 0x3)) == d128_mask32(1, 2, 0x3)
        ? 8 + (u0 & d128_mask32(5, 1, 0x1)) >> (d128_UNIT_BIT_WIDTH - 5 - 1)
        : (u0 & d128_mask32(3, 3, 0x7)) >> (d128_UNIT_BIT_WIDTH - 3 - 3);
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
    result->unit[0] ^= d128_mask32(0, 1, 0x1);
}

void d128_abs(dec128 *result, const dec128 *number)
{
    if (result != number) {
        *result = *number;
    }
    result->unit[0] &= d128_inv_mask32(0, 1, 0x1);
}

/* =========================
 * internal functions.
 */

uint32_t d128_decode_DPD(uint32_t packed)
{
    uint32_t b678;
    uint32_t b34;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;

#define d128_mask10(offset, width, pattern) \
    (((uint32_t)(pattern)) << (10 - width - offset))
#define d128_DPD_b(offset) ((packed >> (9 - offset)) & 0x1)

    b678 = packed & d128_mask10(6, 3, 0x7);
    if (b678 == d128_mask10(6, 3, 0x7)) {
        b34 = packed & d128_mask10(3, 2, 0x3);
        if (b34 == d128_mask10(3, 2, 0x3)) {
            d1 = 8 + d128_DPD_b(2);
            d2 = 8 + d128_DPD_b(5);
            d3 = 8 + d128_DPD_b(9);
        } else if (b34 == d128_mask10(3, 2, 0x2)) {
            d1 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(2);
            d2 = 8 + d128_DPD_b(5);
            d3 = 8 + d128_DPD_b(9);
        } else if (b34 == d128_mask10(3, 2, 0x1)) {
            d1 = 8 + d128_DPD_b(2);
            d2 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(5);
            d3 = 8 + d128_DPD_b(9);
        } else {
            d1 = 8 + d128_DPD_b(2);
            d2 = 8 + d128_DPD_b(5);
            d3 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(9);
        }
    } else if (b678 == d128_mask10(6, 3, 0x6)) {
        d1 = 8 + d128_DPD_b(2);
        d2 = 4 * d128_DPD_b(3) + 2 * d128_DPD_b(4) + d128_DPD_b(5);
        d3 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(9);
    } else if (b678 == d128_mask10(6, 3, 0x5)) {
        d1 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(2);
        d2 = 8 + d128_DPD_b(5);
        d3 = 4 * d128_DPD_b(3) + 2 * d128_DPD_b(4) + d128_DPD_b(9);
    } else if (b678 == d128_mask10(6, 3, 0x4)) {
        d1 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(2);
        d2 = 4 * d128_DPD_b(3) + 2 * d128_DPD_b(4) + d128_DPD_b(5);
        d3 = 8 + d128_DPD_b(9);
    } else {
        d1 = 4 * d128_DPD_b(0) + 2 * d128_DPD_b(1) + d128_DPD_b(2);
        d2 = 4 * d128_DPD_b(3) + 2 * d128_DPD_b(4) + d128_DPD_b(5);
        d3 = 4 * d128_DPD_b(7) + 2 * d128_DPD_b(8) + d128_DPD_b(9);
    }
    return d1 * 100 + d2 * 10 + d3;
}

uint32_t d128_encode_DPD(uint32_t unpacked)
{
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    uint32_t packed;

    d3 = unpacked % 10;
    d2 = ((unpacked - d3) / 10) % 10;
    d1 = unpacked / 100;

#define d128_mask4(offset, width, pattern) \
    (((uint32_t)(pattern)) << (4 - width - offset))
#define d128_DPD_pack(b012, b345, b6, b789) \
    (((b012) << (3 + 1 + 3)) | ((b345) << (1 + 3)) | ((b6) << 3) | (b789))

    if (d1 & d128_mask4(0, 1, 0x1)) {
        if (d2 & d128_mask4(0, 1, 0x1)) {
            if (d3 & d128_mask4(0, 1, 0x1)) {
                packed = d128_DPD_pack(
                    d1 & 0x1,
                    0x6 | (d2 & 0x1),
                    1,
                    0x6 | (d3 & 0x1)
                );
            } else {
                packed = d128_DPD_pack(
                    (d3 & 0x6) | (d1 & 0x1),
                    d2 & 0x1,
                    1,
                    0x6 | (d3 & 0x1)
                );
            }
        } else {
            if (d3 & d128_mask4(0, 1, 0x1)) {
                packed = d128_DPD_pack(
                    (d2 & 0x6) | (d1 & 0x1),
                    0x2 | (d2 & 0x1),
                    1,
                    0x6 | (d3 & 0x1)
                );
            } else {
                packed = d128_DPD_pack(
                    (d3 & 0x6) | (d1 & 0x1),
                    d2 & 0x7,
                    1,
                    0x4 | (d3 & 0x1)
                );
            }
        }
    } else {
        if (d2 & d128_mask4(0, 1, 0x1)) {
            if (d3 & d128_mask4(0, 1, 0x1)) {
                packed = d128_DPD_pack(
                    d1 & 0x7,
                    0x4 | (d2 & 0x1),
                    1,
                    0x6 | (d3 & 0x1)
                );
            } else {
                packed = d128_DPD_pack(
                    d1 & 0x7,
                    (d3 & 0x6) | (d2 & 0x1),
                    1,
                    0x2 | (d3 & 0x1)
                );
            }
        } else {
            if (d3 & d128_mask4(0, 1, 0x1)) {
                packed = d128_DPD_pack(
                    d1 & 0x7,
                    d2 & 0x7,
                    1,
                    d3 & 0x1
                );
            } else {
                packed = d128_DPD_pack(
                    d1 & 0x7,
                    d2 & 0x7,
                    0,
                    d3 & 0x7
                );
            }
        }
    }
    return packed;
}

void d128_convert_to_decoded(dec128_decoded *result, dec128 *number)
{
    result->negative = d128_isSignMinus(number);
    result->kind = (d128_isFinite(number) ? DEC128_FINITE
        : d128_isInfinite(number) ? DEC128_INFINITE
        : d128_isQNaN(number) ? DEC128_QNAN
        : DEC128_SNAN);
    result->exponent = d128_exponent(number);
}
