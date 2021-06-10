程序清单9-12
// ***************************************************************
// stopWatch.cpp
// 一个秒表类，其中使用成员函数进行操作符重载
// ***************************************************************

#include<ctime>
#include<iostream>

using namespace std;

class StopWatch {
public:
	StopWatch(); 	// 构造函数
	void setTime(int newMin, int newSec); 	// 设置秒表时间
    StopWatch operator - (StopWatch&); 	// 计算两个秒表的时间间隔
    void showTime(); 	// 显示时间
private:
    int min;
    int sec; 
};

StopWatch::StopWatch()
{
	min =0;
	sec = 0;
}

void StopWatch:: setTime(int newMin, int newSec)
{
    	min = newMin;
    	sec = newSec;
}

StopWatch StopWatch::operator -(StopWatch& anotherTime)
// 计算两个秒表的时间间隔
// 后置条件：返回值为用StopWatch类型表示的时间间隔
{
	StopWatch tempTime;
	int seconds;						// 两个秒表时间间隔的秒数

	seconds = min * 60 + sec - (anotherTime.min * 60 + anotherTime.sec);
	if (seconds < 0)
		seconds = -seconds;

	tempTime.min = seconds / 60;
	tempTime.sec = seconds % 60;

	return tempTime;
}

void StopWatch::showTime()
{
	if(min >0)
		cout <<min << " minutes " << sec <<" seconds\n";
	else
		cout << sec <<" seconds\n";
}

int main()
{
	StopWatch startTime, endTime, usedTime;

	cout << "按回车键开始！";
	cin.get(); 	// 等待用户输入

	time_t   curtime = time(0); 	// 获取当前系统时间
	tm  tim = *localtime(&curtime); 	// 根据当前时间获取当地时间
	int  min, sec;
	min = tim.tm_min; 	// 得到当地时间的分
	sec = tim.tm_sec;  	// 得到当地时间的秒
	startTime.setTime(min,sec);
	
	cout << "按回车键结束！";
	cin.get(); 	// 等待用户输入

	curtime = time(0); 
	tim = *localtime(&curtime); 
	min = tim.tm_min;
	sec = tim.tm_sec;
	endTime.setTime(min,sec);

	//计算两个时间的间隔,其结果也是StopWatch类型
	usedTime = endTime - startTime ;
	cout << "用时 " ;
	usedTime.showTime();  

	return 0;
}
