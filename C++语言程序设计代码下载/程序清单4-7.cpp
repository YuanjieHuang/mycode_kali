程序清单4-7
// ********************************************
// oneFile.cpp
// ********************************************

#include <iostream> 
using namespace std;

int main()
{
	extern int someInt;
	cout << someInt << endl;
	return 0;
}

// ********************************************
// anotherFile.cpp
// ********************************************
int someInt = 10;

void someFunc()
{
	return;   
}
