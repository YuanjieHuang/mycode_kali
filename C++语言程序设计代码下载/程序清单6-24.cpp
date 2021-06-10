程序清单6-24
// ********************************************************
// structPointer.cpp
// 功能：介绍利用结构变量的指针访问各成员
// ********************************************************

#include <iostream>
#include <cstring>				// 使用strcpy
using namespace std;

struct Student {
    long  num;
    char  name[20];
    char  sex;
    float score;
};

int main()
{
    Student stu;
    Student *pStu;                    	//①

    pStu = &stu;                      	//②

    stu.num = 1000;                  	//③
    strcpy( stu.name, "Linda" );	//③
    stu.sex = 'F';                   	//③
    stu.score = 89.5;               	//③

    cout << pStu -> name << endl;  	//④
    cout << pStu -> num  << endl;   	//④
    cout << pStu -> score << endl; 	//④
    cout << pStu -> sex   << endl; 	//④

    return 0;
}
