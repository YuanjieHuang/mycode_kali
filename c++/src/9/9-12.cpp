//文件名：9-12.cpp
//主模块的实现
#include "Random.h" //包含随机数库
#include <iostream>
using namespace std;

const int RACE_END = 70; //设置跑道的长度

int move_tortoise();
int move_hare();
void print_position(int, int, int);

int main()
{   int hare = 0, tortoise = 0, timer = 0; //hare和tortoise分别是兔子和乌龟的位置，
                                           //timer是计时器，统计比赛用时
    RandomInit(); //随机数初始化
    cout << "timer  tortoise  hare\n"; //输出表头

    while (hare < RACE_END && tortoise < RACE_END) //当兔子和乌龟都没到终点时
    {   tortoise += move_tortoise(); //乌龟移动
        hare += move_hare(); //兔子移动
        print_position(timer, tortoise, hare);
        ++timer;
    }

    if (hare > tortoise) cout << "\n hare wins!\n";
        else cout << "\n tortoise wins!\n";

    return 0;
}

