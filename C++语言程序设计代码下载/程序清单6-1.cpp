程序清单6-1
// ********************************************************
// array1.cpp
// 功能：说明一维数组的声明和引用
// ********************************************************

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	float score[1000];
	float sum = 0.0;
	int num;

	for( num = 0; num < 1000; num ++ ) {
		cin >> score[num];
		sum = sum + score[num];
	}
    
	cout << "The result is " << sum << endl;
	
	return 0;
}
