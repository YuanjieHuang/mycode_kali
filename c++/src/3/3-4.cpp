//文件名：3-4.cpp
//将百分制转换成5个等级(A、B、C、D、E)
#include <iostream>
using namespace std;

int main()
{   int score;

    cout << "请输入分数:";
    cin >> score;

    switch(score / 10) {
        case 10: 
        case 9: cout << "A";   break;
        case 8: cout << "B";   break;
        case 7: cout << "C";   break;
        case 6: cout << "D";   break;
        default: cout << "E";
    } 
    cout << endl;

    return 0;
}

