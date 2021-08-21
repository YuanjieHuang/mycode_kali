//文件名：print.cpp
#include <iostream>
using namespace std;

void print_position(int timer, int t, int h)
{
    if (timer % 6 == 0) cout << endl; //每隔6秒空一行
    cout << timer << '\t' << t << '\t' << h << '\n';
}

