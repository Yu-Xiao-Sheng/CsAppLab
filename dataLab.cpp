#include <stdio.h>

/**
 * 只使用~|实现x&y
 */
int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

/**
 * 取出x中的n号字节  编号从低位到高位从0开始
 */
int getByte(int x, int n)
{
    return (x >> (n << 3)) & 0xff;
}

/**
 * 将x逻辑右移n位 n[0,31]
 */
int logicalShift(int x, int n)
{
    return (x >> n) & ~(((0x1 << 31) >> n) << 1);
}

int logicalShift2(int x, int n)
{
    int a = 1 << 31;
    return ((x & ~a) >> n) | ((!!(x & a)) << (32 + ~n));
}

int main()
{
    // printf("%d\n", bitAnd(1, 1));

    // printf("%d\n", getByte(764, 1));

    printf("%d\n", logicalShift(-1, 1));

    printf("%d\n", logicalShift2(-1, 1));
}