// ***************************************************************
// constrcutorOverloading.cpp
// 构造函数重载
// ***************************************************************
#include <iostream>
#include <string>
using  namespace std;
class ScoreRec {
public:
	// 默认构造函数，将所有项置为空
     ScoreRec()
	{
		name = "";
        	ID = "";
		score =' ';
	}
	// 带参数的构造函数
     ScoreRec(string newName, string newID, char newScore) 
	{
        	name = newName;
		ID = newID;
		score = newScore; 
	}
   	void getRecord(string& nameGet, string& IDGet, char& scoreGet) 
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
    	// 调用默认构造函数可以得到一个各项为空的成绩单
	ScoreRec classA;
	// 调用带参数的构造函数，用实参对类的数据成员进行初始化
	ScoreRec myRec("Henry", "12345", 'A');
    	string  studentName, studentID;
	char studentScore;
    	cout << "Blank score: "<<endl;
    	classA.getRecord(studentName, studentID, studentScore);
	cout << "ID: "<< studentID <<endl;
    	cout << "name: " <<studentName <<endl;
	cout << "Score: " <<studentScore <<endl;
	myRec.getRecord(studentName, studentID, studentScore);
	cout << "My score: "<<endl;
	cout << "ID: "<< studentID <<endl;
    	cout << "name: " <<studentName <<endl;
	cout << "Score: " <<studentScore <<endl;
	return 0;
}
