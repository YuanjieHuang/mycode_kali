// ********************************************************
// dynamicObjPtr.cpp
// 功能：介绍对象的动态创建和撤销
// ********************************************************
#include "date.h"
#include <iostream>
using namespace std;
int main()
{
	Date* datePtr;	//①
	datePtr = new Date(1976, 12 ,20);	//②
	if( datePtr == NULL ) {	//③
		cout << "内存分配失败";
		return 1;
	}
	else { 
		datePtr -> increment();	//④
		datePtr -> print();	//⑤
	}
	delete datePtr;	//⑥
	return 0;
}
