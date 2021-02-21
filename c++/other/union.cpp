// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
联合体（共享空间）：
定义：
union 联合体名称 {  //所有分成员都公用储存单元，因而不能共存
		公有成员
	protected:
		保护型成员
	private：
		私有成员
};

举例：
union Mark{ //表示成绩的联合体
	char grade;	//等级至的成绩
	bool pass;	//只记是否通过课程的成绩
	int percent;//百分制的成绩
};

无名联合：
union {
	int i;
	float f;
	}		//只能给i，f其中一个赋值，共用同样的空间
*/
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class ExamInfo
{
private:
	string name;  //课程名称
	enum {GRADE , PASS, PERCENTAGE } mode;	//枚举法--计分方式 
	union {
		char grade;	//等级制的成绩
		bool pass;  //只记是否通过考试
		int percent; //百分制的成绩
	};
public:
	//三种构造函数，分别用等级、是否通过和百分比初始化
	ExamInfo(string name,char grade)
		:name(name),mode(GRADE),grade(grade) {}
	ExamInfo(string name, bool grade)
		:name(name), mode(PASS), pass(pass) {}
	ExamInfo(string name,  int percent)
		:name(name), mode(PERCENTAGE), percent(percent) {}
	void show();
};

void ExamInfo::show() {
	cout << name << ":";
	switch (mode)
	{
	case GRADE:cout << grade;
		break;
	case PASS: cout << (pass ? "PASS" : "FAIL");
		break;
	case PERCENTAGE: cout << percent;
		break;
	}
	cout << endl;
}

int main()
{
  //  std::cout << "Hello World!\n"; 
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("c++ Programming", 85);
	course1.show();
	course1.show();
	course3.show();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
