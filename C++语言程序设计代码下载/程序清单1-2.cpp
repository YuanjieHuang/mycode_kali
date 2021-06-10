程序清单1-2
// ***************************************************************
// dateToWeek.cpp
// 功能：求用户从键盘输入的一个日期对应的是星期几
// ***************************************************************

#include <iostream>	// 使用其中的cout和cin
#include <string>	// 使用类string

using namespace std;	// 使用名字空间std

class Date {
public:
	Date(int y, int m, int d)
	// 创建Date对象
	// 前置条件：
y年m月d日必须是1582年10月15日之后的某日
    {
		year = y;
		month = m;
		day = d;
	}

	int toWeek()
	// 计算日期所对应的星期数
	// 使用公式	W = [C/4] - 2C + Y + [Y/4] + [13 * (M+1) / 5] + D - 1
	// 其中，W为星期，C为世纪-1，Y为年份（两位数），M为月份，D为日数，[ ]表示取整
	// W除以7的余数即为该日的星期数，余数为0则为星期日
	// 如果月份为1或2，则M分别取13或14，这时C和Y按上一年取值
	// 也就是说，1月和2月要按上一年的13月和 14月来算
	// 例如，2003年1月1日要看作2002年的13月1日来计算
	{
		int w, c, y , m, d;

		// 确定C、Y、M、D的取值
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
		
		if (month == 1 || month == 2) { // 月份为1或2
              c = (year - 1) / 100;
              y = (year - 1) % 100;
			m = month + 12;
		}

		// 计算W
		w = (c/4) - 2 * c + y + (y / 4) + (13 * (m + 1) / 5) + d - 1;

		// 对W为负数的情况进行特殊处理：
		// 对其不断加7直至W为正数。以便W%7的结果符合数论中余数的定义
		while (w < 0) {
			w += 7;	
		}

		return (w % 7);	// 返回W除以7的余数
	}

	void display()
	// 显示日期
	{
		cout << year << '-' << month << '-' << day;
	}

private:
	int year;	// 年份
	int month;	// 月份
	int day;	// 日期
};

// 主函数
int main()
{	
	int year, month, day;	// 年，月，日
	int week;				// 星期数
	string weekName;		// 星期数对应的单词

	cout << "Enter a date after the day of 1582-10-15 "
	      << "and use a blank as spliter:" << endl; 
	cin >> year >> month >> day;	// 输入年、月、日

	Date date(year, month, day);	// 创建Date对象date

	week = date.toWeek();	// 计算对应的星期数

	// 将整数0--6转换为星期数对应的单词
	switch (week) {
		case 0:
			weekName = "Sunday";
			break;
		case 1:
			weekName = "Monday";
			break;
		case 2:
			weekName = "Tuesday";
			break;
		case 3:
			weekName = "Wednesday";
			break;
		case 4:
			weekName = "Thursday";
			break;
		case 5:
			weekName = "Friday";
			break;
		case 6:
			weekName = "Saturday";
			break;
	}

	// 输出结果
	cout << "The day of ";
	date.display();
	cout << " is " << weekName << endl;

	return 0;
}
