程序清单5-2
// **********************************************************
// date.h
// 功能：利用静态全局变量来实现的ADT Date的头文件
// **********************************************************

void set( int, int, int );
int getYear();
int getMonth();
int getDay();
void increment();
void decrement();

// **********************************************************
// date.cpp
// 功能：利用静态全局变量来实现的ADT Date的实现
// **********************************************************

#include "date.h"
#include <iostream>

static int year;
static int month;
static int day;

int daysInMonth( int mo, int yr  );

void set( int nYear, int nMonth, int nDay )
{
    year = nYear;
    month = nMonth;
    day = nDay;
}

int getYear()
{ 
	return year; 
}

int getMonth()
{ 
	return month; 
}

int getDay()
{ 
	return day; 
}

void increment()
{
	day++;
	if (day > daysInMonth(month, year))
	{
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
	}
}

void decrement()
{
	day--;
	if ( day == 0 )
	{
        if( month == 1 )
        { 
             day = 31;
             month = 12;
             year--;
        }
        else
        {
             month--;
             day = daysInMonth( month, year );
        }
	}
}

int daysInMonth( int mo, int yr  )
{
	switch (mo) {
		case 1: 
		case 3: 
		case 5: 
		case 7: 
		case 8: 
		case 10: 
		case 12:
			return 31;
		case 4: 
		case 6: 
		case 9: 
		case 11:
			return 30;
		case 2:  
			if ((yr % 4 == 0 && yr % 100 != 0) ||yr % 400 == 0)
				return 29;
			else
				return 28;
	}
}

// **********************************************************
// dateDemo.cpp
// 功能：使用Date的客户程序
// **********************************************************

#include "date.h"
#include <iostream>

using namespace std;

int main()
{
	int year, month, day;

    cout << "请输入年、月、日：" << endl;
    cin >> year >> month >> day;

    set( year, month, day );

    cout << "Year: " << getYear()<< "   "; 
    cout << "Month: " << getMonth()<< "   ";
    cout << "Day: " << getDay() << endl << endl;

    increment();
    cout << "After incremented 1 day: " << endl;
    cout << "Year: " << getYear() << "   "; 
    cout << "Month: " << getMonth()<< "   ";
    cout << "Day: " << getDay() << endl << endl;
    
    decrement();
    decrement();
    cout << "After decremented 2 days: " << endl;
    cout << "Year: " << getYear()<< "   "; 
    cout << "Month: " << getMonth()<< "   ";
    cout << "Day: " << getDay() << endl << endl;

    return 0;
}
