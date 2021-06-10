程序清单4-9
// ***************************************************
// oneFile.cpp 
// ***************************************************

#include <iostream> 
using namespace std;

int main()
{
	extern int someInt;
	cout << someInt << endl;

	return 0;
}

// ******************************************************
// anotherFile.cpp
// ******************************************************

static int someInt = 10;

void someFunc()
{
	return;   
}
