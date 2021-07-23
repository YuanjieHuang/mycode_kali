//文件名：move.cpp
//移动模块的实现
#include "Random.h"  //本模块用到了随机函数库

int move_tortoise()
{   int probability = RandomInteger(0,9);	//产生0～9的随机数
    if (probability < 5) return 3;	//快走
    else if (probability < 7) return -6;	//后滑
        else return 1;	//慢走
}

int move_hare()
{   int probability = RandomInteger(0,9);
    if (probability < 2) return 0;	//睡觉
    else if (probability < 4) return -9;	//大后滑
        else if (probability < 5) return 14;	//快走
            else if (probability < 8) return 3;	//小步跳
                else return -2;	//慢后滑
} 

