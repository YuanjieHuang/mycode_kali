//文件名：6-1.cpp
//该程序说明了多函数程序的组成及函数的使用
#include <iostream>
using namespace std;

void PrintStar(int); //函数原型声明

//主程序
int main()
{   int n;
 
    cout << "请输入要打印的行数：";
    cin >> n;
 
    PrintStar(n); //函数调用，n为实际参数

    return 0;
}

//函数：PrintStar
//用法：PrintStar(numOfLine)
//作用：在屏幕上显示一个由numOfLine行组成的三角形
void PrintStar(int numOfLine)
{   int i , j;
    for (i = 1; i <= numOfLine; ++i){
        cout << endl;
        for (j = 1; j <= numOfLine - i; ++j)  cout << ' ';
        for (j = 1; j <= 2 * i - 1; ++j)  cout << "*";
    }
    cout << endl;
}

