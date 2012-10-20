#include <cutter.h>
#include "dec128.h"

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={0,0,0}
 */
void test_encode_DPD_000(void)
{
    cut_assert_equal_uint(0x000, d128_encode_DPD(0));
    cut_assert_equal_uint(0x001, d128_encode_DPD(1));
    cut_assert_equal_uint(0x002, d128_encode_DPD(2));
    cut_assert_equal_uint(0x003, d128_encode_DPD(3));
    cut_assert_equal_uint(0x004, d128_encode_DPD(4));
    cut_assert_equal_uint(0x005, d128_encode_DPD(5));
    cut_assert_equal_uint(0x006, d128_encode_DPD(6));
    cut_assert_equal_uint(0x007, d128_encode_DPD(7));

    cut_assert_equal_uint(0x010, d128_encode_DPD(10));
    cut_assert_equal_uint(0x011, d128_encode_DPD(11));
    cut_assert_equal_uint(0x012, d128_encode_DPD(12));
    cut_assert_equal_uint(0x013, d128_encode_DPD(13));
    cut_assert_equal_uint(0x014, d128_encode_DPD(14));
    cut_assert_equal_uint(0x015, d128_encode_DPD(15));
    cut_assert_equal_uint(0x016, d128_encode_DPD(16));
    cut_assert_equal_uint(0x017, d128_encode_DPD(17));

    cut_assert_equal_uint(0x020, d128_encode_DPD(20));
    cut_assert_equal_uint(0x021, d128_encode_DPD(21));
    cut_assert_equal_uint(0x022, d128_encode_DPD(22));
    cut_assert_equal_uint(0x023, d128_encode_DPD(23));
    cut_assert_equal_uint(0x024, d128_encode_DPD(24));
    cut_assert_equal_uint(0x025, d128_encode_DPD(25));
    cut_assert_equal_uint(0x026, d128_encode_DPD(26));
    cut_assert_equal_uint(0x027, d128_encode_DPD(27));

    cut_assert_equal_uint(0x070, d128_encode_DPD(70));
    cut_assert_equal_uint(0x071, d128_encode_DPD(71));
    cut_assert_equal_uint(0x072, d128_encode_DPD(72));
    cut_assert_equal_uint(0x073, d128_encode_DPD(73));
    cut_assert_equal_uint(0x074, d128_encode_DPD(74));
    cut_assert_equal_uint(0x075, d128_encode_DPD(75));
    cut_assert_equal_uint(0x076, d128_encode_DPD(76));
    cut_assert_equal_uint(0x077, d128_encode_DPD(77));

    cut_assert_equal_uint(0x1C0, d128_encode_DPD(340));
    cut_assert_equal_uint(0x1C1, d128_encode_DPD(341));
    cut_assert_equal_uint(0x1C2, d128_encode_DPD(342));
    cut_assert_equal_uint(0x1C3, d128_encode_DPD(343));
    cut_assert_equal_uint(0x1C4, d128_encode_DPD(344));
    cut_assert_equal_uint(0x1C5, d128_encode_DPD(345));
    cut_assert_equal_uint(0x1C6, d128_encode_DPD(346));
    cut_assert_equal_uint(0x1C7, d128_encode_DPD(347));

    cut_assert_equal_uint(0x3F0, d128_encode_DPD(770));
    cut_assert_equal_uint(0x3F1, d128_encode_DPD(771));
    cut_assert_equal_uint(0x3F2, d128_encode_DPD(772));
    cut_assert_equal_uint(0x3F3, d128_encode_DPD(773));
    cut_assert_equal_uint(0x3F4, d128_encode_DPD(774));
    cut_assert_equal_uint(0x3F5, d128_encode_DPD(775));
    cut_assert_equal_uint(0x3F6, d128_encode_DPD(776));
    cut_assert_equal_uint(0x3F7, d128_encode_DPD(777));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={0,0,1}
 */
void test_encode_DPD_001(void)
{
    cut_assert_equal_uint(0x008, d128_encode_DPD(8));
    cut_assert_equal_uint(0x009, d128_encode_DPD(9));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={0,1,0}
 */
void test_encode_DPD_010(void)
{
    cut_assert_equal_uint(0x00A, d128_encode_DPD(80));
    cut_assert_equal_uint(0x01A, d128_encode_DPD(90));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={0,1,1}
 */
void test_encode_DPD_011(void)
{
    cut_assert_equal_uint(0x04E, d128_encode_DPD(88));
    cut_assert_equal_uint(0x04F, d128_encode_DPD(89));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={1,0,0}
 */
void test_encode_DPD_100(void)
{
    cut_assert_equal_uint(0x00C, d128_encode_DPD(800));
    cut_assert_equal_uint(0x08C, d128_encode_DPD(900));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={1,0,1}
 */
void test_encode_DPD_101(void)
{
    cut_assert_equal_uint(0x02E, d128_encode_DPD(808));
    cut_assert_equal_uint(0x02F, d128_encode_DPD(809));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={1,1,0}
 */
void test_encode_DPD_110(void)
{
    cut_assert_equal_uint(0x00E, d128_encode_DPD(880));
    cut_assert_equal_uint(0x01E, d128_encode_DPD(890));
}

/*
 * patterns {d(1,0),d(2,0),d(3,0)}={1,1,1}
 */
void test_encode_DPD_111(void)
{
    cut_assert_equal_uint(0x06E, d128_encode_DPD(888));
    cut_assert_equal_uint(0x06F, d128_encode_DPD(889));
}
