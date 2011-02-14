#ifndef _DEC128_H
#define _DEC128_H 1

#include <stdint.h>

#ifndef bool
#define bool int
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#define d128_P 34
#define d128_EMAX 6144
#define d128_BIAS 6176
#define d128_COMBINATION_FIELD_BIT_WIDTH 17
#define d128_TRAILING_SIGNIFICAND_FIELD_BIT_WIDTH 110
#define d128_STROAGE_BIT_WIDTH 128

#define d128_UNIT_BIT_WIDTH 32
#define d128_UNIT_COUNT 4

typedef struct {
    uint32_t unit[d128_UNIT_COUNT];
} dec128;

#define d128_is754version1985() false /* not yet conforms */
#define d128_is754version2008() false /* not yet conforms */

#define d128_mask32(offset, width, pattern) \
    (((uint32_t)(pattern)) << (32 - width - offset))
#define d128_inv_mask32(offset, width, pattern) \
    (((uint32_t)0xFFFFFFFF) ^ d128_mask(offset, width, pattern))

inline bool d128_isSignMinus(dec128 *number);
inline bool d128_isNaN(dec128 *number);
inline bool d128_isSNaN(dec128 *number);
inline bool d128_isQNaN(dec128 *number);
inline bool d128_isInfinite(dec128 *number);
inline bool d128_isFinite(dec128 *number);
inline bool d128_isZero(dec128 *number);

int32_t d128_exponent(dec128 *number);

void d128_setUnits(dec128 *number, uint32_t u0, uint32_t u1, uint32_t u2,
    uint32_t u3);
void d128_setZero(dec128 *number);
void d128_setInfinite(dec128 *number);
void d128_setSNaN(dec128 *number);
void d128_setQNaN(dec128 *number);

void d128_copy(dec128 *result, const dec128 *number);
void d128_negate(dec128 *result, const dec128 *number);
void d128_abs(dec128 *result, const dec128 *number);

#endif /* _DEC128_H */
