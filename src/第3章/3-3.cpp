//文件名：3-3.cpp
//将输入整数转换成星期中的某一天的名字
#include <iostream>
using namespace std;

int main()
{   int day;

    cout << "请输入一个整型数（0：星期天;1：星期一;……,6：星期六）:";
    cin >> day;

    switch (day) {
	case 0: cout << "星期天" << endl; break;
	case 1: cout << "星期一" << endl; break;
	case 2: cout << "星期二" << endl; break; 
	case 3: cout << "星期三" << endl; break; 
	case 4: cout << "星期四" << endl; break; 
	case 5: cout << "星期五" << endl; break; 
	case 6: cout << "星期六" << endl; break;
　  }

    return 0;
}

