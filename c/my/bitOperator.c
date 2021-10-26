#include "stdio.h"
#include "stdlib.h"

typedef enum{false,true} bool;
bool isOdd(int a)
{
    return a & 1;
}

bool isOdd2(int a)
{
    return a % 2;
}

bool isEquil(int a, int b)
{
    return !(a ^ b);
}

void set_bit(int* a, int pos)//pos+1位 置1
{
    *a |= 1 << pos;
}

void clr_bit(int* a, int pos)
{
    *a &= ~(1 << pos);
}

void get_bit(int* a, int pos)
{
    *a & (1 << pos);
}


//交换符号将正数变成负数，负数变成正数
int reversal(int a) {
  return ~a + 1;
}

int abs(int a) {
  int i = a >> 31;
  return i == 0 ? a : (~a + 1);
}

int abs2(int a) {
  int i = a >> 31;
  return ((a^i) - i);
}

int swapHigh8BitWithLow8Bit(unsigned short a)
{
    a = (a >> 8) | (a << 8);
    return a;
}

int reverseBit(unsigned short a)//二进制逆序
{
    a = ((a & 0xAAAA) >> 1) | ((a & 0x5555) << 1);
    a = ((a & 0xCCCC) >> 2) | ((a & 0x3333) << 2);
    a = ((a & 0xF0F0) >> 4) | ((a & 0x0F0F) << 4);
    a = ((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8);
    return a;
}

unsigned int count_1_nums_in_bits(unsigned int a)//统计二进制中 1 的个数
{
    unsigned int count = 0;  
    while(a){  
        a = a & (a - 1);  
        count++;  
    }
    return count; 
}

int remove_last_1(unsigned int x)//用于消去x最后一位的1
{
   return x & (x - 1);
}

int reserve_last_1(int x)//保留x最后一位的1
{
   return x & (-x);
}

int all_1 = ~0;

bool isHighestBit_1(int a)
{
    return a < 0;
}

int reserveBits(int a, int pos)//保留最后i-1位；
{
    return a & ((1<<pos)-1);
}

int clrBits(int a, int pos)//清零最后i-1位；
{
    return a & ~((1<<pos)-1);
}

int getHighBit_1(int a)//得到最高位的1；?
{
    a = a | (a>>1);
    a = a | (a>>2);
    a = a | (a>>4);
    a = a | (a>>8);
    a = a | (a>>16);
    return (a+1)>>1;
}

/*
1 用 O(1) 时间检测整数 n 是否是 2 的幂次。

2 计算在一个 32 位的整数的二进制表式中有多少个 1。
*/
void swap_xor(int* a, int* b)
{
    if(*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void f(int a, int b, int i)
{
    a |= 1<<i;
    a & (b & 1<<i);
}

int main()
{
    int a = -11;
    printf("%d ", reversal(a));
    printf("%d ", abs(a));
    printf("%d ", abs2(a));
    printf("%#X %#X ",34520, swapHigh8BitWithLow8Bit((unsigned short)34520));
    printf("%#X %#d ",0b1000011011011000, reverseBit(0b1000011011011000));
    return 0;
}