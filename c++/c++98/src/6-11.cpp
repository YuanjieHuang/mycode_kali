//文件名：6-11.cpp
//打印一个十进制整数
#include <iostream>
using namespace std;

void printInt(int);  //输出一个整型数

int main()
{   int num;

    cout << "请输入一个整型数：" << endl;
    cin >> num;

    printInt(num);
    cout << endl;

    return 0;
}

//作用：以十进制打印非负整数num
//用法：printInt(1234)
void printInt(int num)
{   if (num < 10)     //递归终止条件
        cout << static_cast<char>(num+'0');  
    else {
         printInt(num/10);
         cout << static_cast<char>(num%10 + '0');
    }
}

