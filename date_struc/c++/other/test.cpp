#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <string>
using namespace std;

class ExamInfo
{
private:
	string name;  //课程名称
	enum {GRADE , PASS, PERCENTAGE } mode;	//计分方式
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

int main(int argc, char** argv) {	
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("c++ Programming", 85);
	course1.show();
	course1.show();
	course3.show();
	return 0;
}
