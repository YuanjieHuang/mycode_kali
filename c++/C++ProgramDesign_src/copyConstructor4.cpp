// **************************************************************
// copyConstructor4.cpp
// 复制构造函数及其使用的第4个示例
// ***************************************************************
#include <iostream>
#include <string>
using  namespace std;
// 学生成绩的类
class ScoreRec {
public:
	ScoreRec()
	{
		name = NULL;
		ID = NULL;
		score = ' '; 
		cout << "Default constructor...\n";
	}
	~ScoreRec()
	{
		if(name != NULL)
			delete [] name;
		if( ID != NULL)
			delete [] ID;
		cout << "Deconstructor...\n";
	}
    // 带参数的构造函数
	ScoreRec(char * newName, char * newID, char newScore)
	{
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
		ID = new char[strlen(newID) + 1];
		strcpy(ID, newID);
		score = newScore; 
		cout << "Constructor with parameters...\n";
	}
    // 复制构造函数
	ScoreRec( ScoreRec& anotherScoreRec)
	{
		name = new char[strlen (anotherScoreRec.name) + 1];
		ID = new char[strlen (anotherScoreRec.ID) + 1]; 
		strcpy(name, anotherScoreRec.name);
		strcpy(ID, anotherScoreRec.ID);
		score = anotherScoreRec.score;
		cout << "Copy constructor...\n";
	}
	void getScoreRec(char * nameGet, char * IDGet, char& scoreGet)
	{
		strcpy(nameGet , name) ;
		strcpy(IDGet , ID) ;
		scoreGet = score;
	}
	void setName(char *newName)
	{
		if(name != NULL)
			delete [] name;
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
	}
	void setID(char *newID)
	{
		if(ID != NULL)
			delete [] ID;
		ID = new char[strlen(newID) + 1];
		strcpy(ID, newID);
	}
	void setScore(char newScore)
	{
		score = newScore;
	}
private:
	char * name;
	char * ID;
	char score; // A-F
};
ScoreRec setScoreRec(char * newName, char * newID, char newScore)
// 设置一个成绩记录的值
// 前置条件：newName, newID, newScore已赋值
// 后置条件：设置各项值 
{
	ScoreRec tempRec;
	tempRec.setName(newName);
	tempRec.setID(newID);
	tempRec.setScore(newScore);
	return tempRec;
}
void writeScoreRec(ScoreRec &rec)
// 输出一个成绩记录的值
// 前置条件：rec已赋值
// 后置条件：输出各项值 
{
     char studentName[50], studentID[50];
	char studentScore;
 	rec.getScoreRec(studentName, studentID, studentScore);
	cout << "ID: "<< studentID << endl;
     cout << "name: " << studentName << endl;
	cout << "Score: " << studentScore << endl;
	return ;
}
int main()
{
	char studentName[50] = "Henry";
	char studentID[50] ="123456";
	char studentScore ='A';
     writeScoreRec(setScoreRec(studentName, studentID, studentScore));
	return 0;
}
