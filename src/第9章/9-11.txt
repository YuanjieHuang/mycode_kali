//文件：Random.cpp
//该文件实现了Random库
#include <cstdlib>
#include <ctime>
#include "Random.h"

//函数：RandomInit
//该函数取当前系统时间作为随机数发生器的种子
void RandomInit()
{
    srand(time(NULL));
}

//函数：RandomInteger
//该函数将0到RAND_MAX的区间的划分成high-low+1个子区间。
//当产生的随机数落在第一个子区间时，则映射成low。当落在最后一个子区间时，
//映射成high。当落在第i个子区间时（i从0到high-low），则映射到low + i
int RandomInteger(int low, int high)
{
    return (low + (high - low + 1) * rand() / (RAND_MAX + 1));
}

