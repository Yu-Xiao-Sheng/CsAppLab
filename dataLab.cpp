#include <stdio.h>

/**
 * 只使用~|实现x&y
 */
int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

/**
 * 取出x中的第n字节  编号从低位到高位从0开始
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

/**
 * 获取最小的整数补码
*/
int tmin(){
    return 1 << 31;
}

/**
 * x是最大的整数补码则返回1，否则返回0  0x7fffffff => 1  other => 0
 * 0111 + 1 => 1000   ~1000 => 0111
 * !!(x+1) => 只有在x为-1时，才为假，排除-1
*/
int isTmax(int x){
    return !((~(x+1))^x) & !!(x+1);
}


/**
 * x的奇数位都为1时为真
*/
int allOddBits(int x){
    // 通过位运算构造一个奇数位全为1的数字，任意数x与这个数做按位与，等于这个数本身则符合条件
    int a = 0x55 << 8;
    int b = a | 0x55;
    int c = b << 16 | b;
    return !((x & c)^c);
}

/**
 * 求x的相反数，negate(1) -> -1
 * 主要根据 A + ~A = -1  和 A + -A = 0  得到 -A = ~A + 1
 * 
*/
int negate(int x){
    return ~x + 1;
}

/**
 * 0x30⩽x⩽0x39时为真 字符“0”到“9”的ASCII代码值
 * 首先检测高4位是否为3，然后检测后4位-A(-10)是否为负数来判断是否在合理范围
*/
int isAsciDigit(int x){
    int a = (x & 0xf);
    int b = ~0xA + 1;
    int c = 0x80 << 1;
    return !((x >> 4) ^ 0x3) & ((a + b) & c);
}

int main()
{
    // printf("%d\n", bitAnd(1, 1));

    // printf("%d\n", getByte(764, 0));

    // printf("%d\n", logicalShift(-1, 1));

    // printf("%d\n", logicalShift2(-1, 1));

    // printf("%d\n", tmin());

    // printf("%d\n", isTmax(0x7fffffff));

    
    // printf("%d\n", allOddBits(1465210197));

    // printf("%d\n", negate(17));

    printf("%d\n", isAsciDigit(0x36));
}