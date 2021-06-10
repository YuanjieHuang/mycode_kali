程序清单9-9
// ***************************************************************
// copyConstructor2.cpp
// 复制构造函数及其使用的第2个示例
// ***************************************************************

#include <iostream>
#include <string>
using  namespace std;

// 学生成绩的类
class ScoreRec {
public:
	// 默认构造函数，将所有项置为空
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

private:
	char * name;
	char * ID;
	char score; // A-F
};

int main()
{
	// 调用带参数的构造函数，用参数对myRec的数据成员进行初始化
	ScoreRec myRec("Henry", "12345", 'A');
    	// 调用复制构造函数，用已有的类对象myRec初始化新的类对象myNewRec
	ScoreRec myNewRec (myRec);
    	char studentName[50], studentID[50];
	char studentScore;

	myRec.getScoreRec(studentName, studentID, studentScore);
	cout << endl << "My score:\n";
	cout << "ID: "<< studentID << endl;
    	cout << "name: " <<studentName << endl;
	cout << "Score: " <<studentScore << endl;

	myNewRec.getScoreRec(studentName, studentID, studentScore);
	cout << endl << "My new score:\n";
	cout << "ID: "<< studentID << endl;
    	cout << "name: " <<studentName << endl;
	cout << "Score: " <<studentScore << endl << endl;

	return 0;
}
