//文件：Random.h
//随机函数库的头文件
#ifndef _random_h
#define _random_h

//函数：RandomInit
//用法：RandomInit()
//作用：此函数初始化随机数发生器
void RandomInit();

//函数：RandomInteger
//用法：n = RandomInteger(low, high)
//作用：此函数返回一个low到high之间的随机数，包括low和high
int RandomInteger(int low, int high);

#endif

