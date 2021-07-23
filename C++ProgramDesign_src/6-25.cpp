// ********************************************************
// objectPtr.cpp
// 功能：介绍利用对象指针访问对象的成员
// ********************************************************
#include "date.h"
#include <iostream>
using namespace std;
int main()
{
    Date* datePtr;	//①
    Date date(1976, 12 ,20);	//②
    datePtr = &date;	//③
    date.print();	//④
    datePtr->print();	//⑤
    return 0;
}
