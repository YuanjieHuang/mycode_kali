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
