// ***************************************************************
// studentRec.h
// 功能：声明结构类型StudentRec的头文件
// ***************************************************************
#include <string>
using namespace std;
struct  StudentRec	   
{		
    string stuNum;    
    string stuName;   
    int score1;       
    int score2;       
    bool admit;        
} ;
// ***************************************************************
// client.cpp
// 功能：使用结构类型StudentRec的客户程序，演示结构类型作函数参数的使用方法
// ***************************************************************
#include "studentRec.h"
#include <iostream>
using namespace std;
void input( StudentRec& student )	// 这里必须使用引用形参
{
	cout << "Please enter the student's name: ";
	cin >> student.stuName; 
	cout <<  "Please enter the student's number: ";
	cin >> student.stuNum; 
	cout << "Please enter the student's 2 scores: ";
	cin >> student.score1 >> student. score2;
	cout << "Please enter whether the student is admitted( 0 for No, 1 for Yes): ";
	cin >> student.admit;
}
bool check( StudentRec& student )	// 这里引用形参或值形参均可使用
{
	int mean = (student.score1 + student.score2)/2;
	if( ( mean < 60 && student.admit == false ) ||
		( mean >= 60 && student.admit == true ) )
		return true;
	else 
		return false;
}
int main()
{
	StudentRec stu1;
	input(stu1);
	if(check(stu1)) 
		cout << "Correct input." << endl;
	else                   
		cout << "Wrong input." << endl;
	return 0;
}
