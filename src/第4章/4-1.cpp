//文件名：4-1.cpp
//统计考试分数中的最高分，最低分和平均分
#include<iostream>
using namespace std;

int main()
{   int value, total, max, min, i;//value存放当前输入数据，i为循环变量
    //变量的初始化
    total = 0;
    max = 0;
    min = 100;

    for (i=1; i<=100; ++i){
	  cout << "\n请输入第" << i << "个人的成绩：";
	  cin >> value;
	  total += value;
	  if (value > max) max = value;
	  if (value < min) min = value;
    }

    cout << "\n最高分：" << max << endl;
    cout << "最低分：" << min << endl;
    cout << "平均分：" << total / 100 << endl;

    return 0;
}

