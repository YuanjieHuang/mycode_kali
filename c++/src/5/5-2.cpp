//文件名：5-2.cpp
//统计及打印成绩单
#include <iostream>
using namespace std;
#define MAX 50  //定义一个班级中最多的学生数
int main()
{   int score[MAX], max = 0, min = 100, sum = 0, num, average, i;
    //max为最高分，min为最低分，sum为总分，num为学生数，average为平均分

    cout << "请输入成绩（-1表示结束）：\n";
    for (num = 0; num < MAX; ++num){
         cin >> score[num];
	if (score[num] == -1) break;
	sum += score[num];
	if (score[num] > max) max = score[num];
	if (score[num] < min) min = score[num];
    }

    average = sum / num; 	//计算平均成绩

    cout << "\n成绩清单：\n";
    cout << "编号\t成绩\t最高分\t最低分\t平均分\n";
    for (i = 0; i < num; ++i)
        cout << i << ‘\t’ << score[i] << '\t' << max << '\t' << min << '\t' << average
             << '\n';

    return 0;
}

