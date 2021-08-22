// ***************************************************************
// assignmentOverloading.cpp
// 赋值运算符重载
// ***************************************************************
#include <iostream>
// #include <string>
#include <cstring>
using  namespace std;
// 学生成绩的类
class ScoreRec {
public:
	ScoreRec()
	{
		name = NULL;
		ID = NULL;
		score = ' '; 
		cout <<"Default constructor...\n";
	}
	~ScoreRec()
	{
		if(name != NULL)
			delete [] name;
		if( ID != NULL)
			delete [] ID;
		cout <<"Deconstructor...\n";
	}
    // 带参数的构造函数
	ScoreRec(char * newName, char * newID, char newScore)
	{
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
		ID = new char[strlen(newID) + 1];
		strcpy(ID, newID);
		score = newScore; 
		cout <<"Constructor with parameters...\n";
	}
    // 复制构造函数
	ScoreRec( ScoreRec& anotherScoreRec)
	{
		name = new char[strlen (anotherScoreRec.name) + 1];
		ID = new char[strlen (anotherScoreRec.ID) + 1]; 
		strcpy(name, anotherScoreRec.name);
		strcpy(ID, anotherScoreRec.ID);
		score = anotherScoreRec.score;
		cout <<"Copy constructor...\n";
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
    // 赋值操作符重载函数
	ScoreRec& operator= (const ScoreRec& anotherScoreRec)
	{
		if (name!=NULL) 
			delete []name;
		if (ID !=NULL) 
			delete []ID;
		name = new char[strlen (anotherScoreRec.name) + 1];
		ID = new char[strlen (anotherScoreRec.ID) + 1]; 
		strcpy(name, anotherScoreRec.name);
		strcpy(ID, anotherScoreRec.ID);
		score = anotherScoreRec.score;
		return *this;
	}
private:
	char * name;
	char * ID;
	char score; // A-F
};
ScoreRec setScoreRec(char * newName, char * newID, char newScore)
{
     ScoreRec tempRec;
	tempRec.setName(newName);
	tempRec.setID(newID);
	tempRec.setScore(newScore);
	return tempRec;
}
void writeScoreRec(ScoreRec &rec)
{
     char studentName[50], studentID[50];
	char studentScore;
 	rec.getScoreRec(studentName, studentID, studentScore);
	cout << "ID: "<< studentID <<endl;
     cout << "name: " <<studentName <<endl;
	cout <<"Score: " <<studentScore << endl;
	return ;
}
int main()
{
	char studentName[50] = "Henry";
	char studentID[50] = "123456";
	char studentScore = 'A';
     ScoreRec tempRec;
	tempRec = setScoreRec(studentName, studentID, studentScore); 
     writeScoreRec(tempRec);
	return 0;
}
