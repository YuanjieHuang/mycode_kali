//文件名：6-3.cpp
//计算10位学生的平均成绩的函数及使用
#include <iostream>
using namespace std;

int average(int array[10]); //函数原型声明

int main()
{   int i, score[10];

    cout << "请输入10个成绩：" << endl;
    for ( i = 0; i < 10; i++)  cin >> score[i];

    cout << "平均成绩是：" << average(score) << endl;

    return 0;
}

int average(int array[10])
{   int i, sum = 0;

    for (i = 0; i < 10; ++i)  sum += array[i];

    return sum / 10;
 }

