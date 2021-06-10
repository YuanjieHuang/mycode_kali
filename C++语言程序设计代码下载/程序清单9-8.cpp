程序清单9-8
// **************************************************************
// copyConstructor1.cpp
// 复制构造函数及其使用的第1个示例
// **************************************************************

#include <iostream>
#include <string>
using  namespace std;

// 学生成绩的类
class ScoreRec {
public:
	// 默认构造函数，将所有项置为空
	ScoreRec()
	{
		name = "";
		ID = "";
		score = ' '; 
		cout <<"Default constructor...\n";
	} 

     // 带参数的构造函数
	ScoreRec(string newName, string newID, char newScore)
	{
		name = newName;
		ID = newID;
		score = newScore; 
		cout <<"Constructor with parameters...\n";
	} 

     // 复制构造函数
	ScoreRec( ScoreRec& anotherScoreRec)
	{
		name = anotherScoreRec.name;
		ID = anotherScoreRec.ID;
		score = anotherScoreRec.score;
		cout <<"Copy constructor...\n";
	}

	void getScoreRec(string& nameGet, string& IDGet, char& scoreGet)
	{
		nameGet = name ;
		IDGet = ID;
		scoreGet = score;
	}

private:
	string name;
	string ID;
	char score; // A-F
};

int main()
{
   	//调用默认构造函数可以得到一个各项为空的成绩单
	ScoreRec classA;
	//调用带参数的构造函数,用参数对类的数据成员进行初始化
	ScoreRec myRec("Henry", "12345", 'A');
    	//调用复制构造函数，用已有的类对象myRec初始化新的类对象myNewRec
	ScoreRec myNewRec (myRec);
     string  studentName, studentID;
	char studentScore;

	cout << "Blank score:\n";
     classA.getScoreRec(studentName, studentID, studentScore);
	cout << "ID: "<< studentID << endl;
     cout << "Name: " << studentName << endl;
	cout << "Score: " << studentScore << endl;

	myRec.getScoreRec(studentName, studentID, studentScore);
	cout << "My score:\n";
	cout << "ID: "<< studentID << endl;
     cout << "Name: " << studentName << endl;
	cout << "Score: " << studentScore << endl;

	myNewRec.getScoreRec(studentName, studentID, studentScore);
	cout << "My new score:\n";
	cout << "ID: "<< studentID << endl;
     cout << "Name: " << studentName << endl;
	cout << "Score: " << studentScore << endl;

	return 0;
}
