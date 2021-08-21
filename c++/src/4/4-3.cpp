//文件名：4-3.cpp
//统计考试成绩中的最高分，最低分和平均分
#include<iostream>
using namespace std;

int main()
{   int value, total, max, min, noOfInput;

    total = 0; //总分
    max = 0;
    min = 100;
    noOfInput = 0;//人数

    cout << "请输入第1位学生的成绩：";
    cin >> value;
    while (value != -1){
        ++noOfInput;
	      total += value;
	      if (value > max) max = value;
	      if (value < min) min = value;
	      cout << "\n请输入第" << noOfInput + 1 << "个人的成绩：";
	      cin >> value;
    }

    cout << "\n最高分：" << max << endl;
    cout << "最低分：" << min << endl;
    cout << "平均分：" << total / noOfInput << endl;

    return 0;
}

