//文件名：6-12.cpp
//打印二进制、八进制、十进制和十六进制整数
#include <iostream>
using namespace std;

const char DIGIT[17]="0123456789abcdef";
void printInt(int,int);
int main()
{   int num,base;

    cout << "请输入一个整型数：" << endl;
    cin >> num;
    cout << "请输入要打印的数制：" << endl;
    cin >> base;

    printInt(num, base);
    cout << endl;

    return 0;
}

//作用：以数制base打印非负整数num
//用法：printInt(1234, 8)
void printInt(int num, int base)
{   if  (num < base) cout << DIGIT[num];
    else {
         printInt(num/base, base);
         cout << DIGIT[num%base];
    }
}

