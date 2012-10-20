#include <cutter.h>
#include "dec128.h"

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={0,x,x,x,x} (x=0,1)
 */
void test_decode_DPD_0xxxx(void)
{
    cut_assert_equal_uint(  0, d128_decode_DPD(0x000));
    cut_assert_equal_uint(  1, d128_decode_DPD(0x001));
    cut_assert_equal_uint(  2, d128_decode_DPD(0x002));
    cut_assert_equal_uint(  3, d128_decode_DPD(0x003));
    cut_assert_equal_uint(  4, d128_decode_DPD(0x004));

    cut_assert_equal_uint( 10, d128_decode_DPD(0x010));
    cut_assert_equal_uint( 11, d128_decode_DPD(0x011));
    cut_assert_equal_uint( 12, d128_decode_DPD(0x012));

    cut_assert_equal_uint( 25, d128_decode_DPD(0x025));

    cut_assert_equal_uint( 36, d128_decode_DPD(0x036));

    cut_assert_equal_uint(147, d128_decode_DPD(0x0C7));

    cut_assert_equal_uint(250, d128_decode_DPD(0x150));

    cut_assert_equal_uint(361, d128_decode_DPD(0x1E1));

    cut_assert_equal_uint(476, d128_decode_DPD(0x276));

    cut_assert_equal_uint(504, d128_decode_DPD(0x284));

    cut_assert_equal_uint(633, d128_decode_DPD(0x333));

    cut_assert_equal_uint(756, d128_decode_DPD(0x3D6));

    cut_assert_equal_uint(777, d128_decode_DPD(0x3F7));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,0,0,x,x} (x=0,1)
 */
void test_decode_DPD_100xx(void)
{
    cut_assert_equal_uint(  8, d128_decode_DPD(0x008));
    cut_assert_equal_uint(  9, d128_decode_DPD(0x009));

    cut_assert_equal_uint( 18, d128_decode_DPD(0x018));

    cut_assert_equal_uint(128, d128_decode_DPD(0x0A8));

    cut_assert_equal_uint(279, d128_decode_DPD(0x179));

    cut_assert_equal_uint(358, d128_decode_DPD(0x1D8));

    cut_assert_equal_uint(669, d128_decode_DPD(0x369));

    cut_assert_equal_uint(738, d128_decode_DPD(0x3B8));

    cut_assert_equal_uint(778, d128_decode_DPD(0x3F8));
    cut_assert_equal_uint(779, d128_decode_DPD(0x3F9));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,0,1,x,x} (x=0,1)
 */
void test_decode_DPD_101xx(void)
{
    cut_assert_equal_uint( 80, d128_decode_DPD(0x00A));
    cut_assert_equal_uint( 81, d128_decode_DPD(0x00B));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,1,0,x,x} (x=0,1)
 */
void test_decode_DPD_110xx(void)
{
    cut_assert_equal_uint(800, d128_decode_DPD(0x00C));
    cut_assert_equal_uint(801, d128_decode_DPD(0x00D));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,1,1,0,0}
 */
void test_decode_DPD_11100(void)
{
    cut_assert_equal_uint(880, d128_decode_DPD(0x00E));
    cut_assert_equal_uint(881, d128_decode_DPD(0x00F));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,1,1,0,1}
 */
void test_decode_DPD_11101(void)
{
    cut_assert_equal_uint(808, d128_decode_DPD(0x02E));
    cut_assert_equal_uint(809, d128_decode_DPD(0x02F));

    cut_assert_equal_uint(818, d128_decode_DPD(0x03E));
    cut_assert_equal_uint(828, d128_decode_DPD(0x12E));
    cut_assert_equal_uint(838, d128_decode_DPD(0x13E));
    cut_assert_equal_uint(848, d128_decode_DPD(0x22E));
    cut_assert_equal_uint(858, d128_decode_DPD(0x23E));
    cut_assert_equal_uint(868, d128_decode_DPD(0x32E));
    cut_assert_equal_uint(878, d128_decode_DPD(0x33E));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,1,1,1,0}
 */
void test_decode_DPD_11110(void)
{
    cut_assert_equal_uint( 88, d128_decode_DPD(0x04E));
    cut_assert_equal_uint( 89, d128_decode_DPD(0x04F));

    cut_assert_equal_uint( 98, d128_decode_DPD(0x05E));
    cut_assert_equal_uint( 99, d128_decode_DPD(0x05F));

    cut_assert_equal_uint(188, d128_decode_DPD(0x0CE));
    cut_assert_equal_uint(288, d128_decode_DPD(0x14E));
    cut_assert_equal_uint(388, d128_decode_DPD(0x1CE));
    cut_assert_equal_uint(488, d128_decode_DPD(0x24E));
    cut_assert_equal_uint(588, d128_decode_DPD(0x2CE));
    cut_assert_equal_uint(688, d128_decode_DPD(0x34E));
    cut_assert_equal_uint(788, d128_decode_DPD(0x3CE));

    cut_assert_equal_uint(189, d128_decode_DPD(0x0CF));
    cut_assert_equal_uint(289, d128_decode_DPD(0x14F));
    cut_assert_equal_uint(389, d128_decode_DPD(0x1CF));
    cut_assert_equal_uint(489, d128_decode_DPD(0x24F));
    cut_assert_equal_uint(589, d128_decode_DPD(0x2CF));
    cut_assert_equal_uint(689, d128_decode_DPD(0x34F));
    cut_assert_equal_uint(789, d128_decode_DPD(0x3CF));

    cut_assert_equal_uint(198, d128_decode_DPD(0x0DE));
    cut_assert_equal_uint(298, d128_decode_DPD(0x15E));
    cut_assert_equal_uint(398, d128_decode_DPD(0x1DE));
    cut_assert_equal_uint(498, d128_decode_DPD(0x25E));
    cut_assert_equal_uint(598, d128_decode_DPD(0x2DE));
    cut_assert_equal_uint(698, d128_decode_DPD(0x35E));
    cut_assert_equal_uint(798, d128_decode_DPD(0x3DE));

    cut_assert_equal_uint(199, d128_decode_DPD(0x0DF));
    cut_assert_equal_uint(299, d128_decode_DPD(0x15F));
    cut_assert_equal_uint(399, d128_decode_DPD(0x1DF));
    cut_assert_equal_uint(499, d128_decode_DPD(0x25F));
    cut_assert_equal_uint(599, d128_decode_DPD(0x2DF));
    cut_assert_equal_uint(699, d128_decode_DPD(0x35F));
    cut_assert_equal_uint(799, d128_decode_DPD(0x3DF));
}

/*
 * patterns {b(6),b(7),b(8),b(3),b(4)}={1,1,1,1,1}
 */
void test_decode_DPD_11111(void)
{
    cut_assert_equal_uint(888, d128_decode_DPD(0x06E));
    cut_assert_equal_uint(888, d128_decode_DPD(0x16E));
    cut_assert_equal_uint(888, d128_decode_DPD(0x26E));
    cut_assert_equal_uint(888, d128_decode_DPD(0x36E));

    cut_assert_equal_uint(889, d128_decode_DPD(0x06F));
    cut_assert_equal_uint(889, d128_decode_DPD(0x16F));
    cut_assert_equal_uint(889, d128_decode_DPD(0x26F));
    cut_assert_equal_uint(889, d128_decode_DPD(0x36F));

    cut_assert_equal_uint(898, d128_decode_DPD(0x07E));
    cut_assert_equal_uint(898, d128_decode_DPD(0x17E));
    cut_assert_equal_uint(898, d128_decode_DPD(0x27E));
    cut_assert_equal_uint(898, d128_decode_DPD(0x37E));

    cut_assert_equal_uint(899, d128_decode_DPD(0x07F));
    cut_assert_equal_uint(899, d128_decode_DPD(0x17F));
    cut_assert_equal_uint(899, d128_decode_DPD(0x27F));
    cut_assert_equal_uint(899, d128_decode_DPD(0x37F));

    cut_assert_equal_uint(988, d128_decode_DPD(0x0EE));
    cut_assert_equal_uint(988, d128_decode_DPD(0x1EE));
    cut_assert_equal_uint(988, d128_decode_DPD(0x2EE));
    cut_assert_equal_uint(988, d128_decode_DPD(0x3EE));

    cut_assert_equal_uint(989, d128_decode_DPD(0x0EF));
    cut_assert_equal_uint(989, d128_decode_DPD(0x1EF));
    cut_assert_equal_uint(989, d128_decode_DPD(0x2EF));
    cut_assert_equal_uint(989, d128_decode_DPD(0x3EF));

    cut_assert_equal_uint(998, d128_decode_DPD(0x0FE));
    cut_assert_equal_uint(998, d128_decode_DPD(0x1FE));
    cut_assert_equal_uint(998, d128_decode_DPD(0x2FE));
    cut_assert_equal_uint(998, d128_decode_DPD(0x3FE));

    cut_assert_equal_uint(999, d128_decode_DPD(0x0FF));
    cut_assert_equal_uint(999, d128_decode_DPD(0x1FF));
    cut_assert_equal_uint(999, d128_decode_DPD(0x2FF));
    cut_assert_equal_uint(999, d128_decode_DPD(0x3FF));
}
