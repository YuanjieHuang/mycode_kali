//文件名：4-2.cpp
//打印九九乘法表
#include<iostream>
using namespace std;

void main()
{   int i, j;

    for (i=1; i<=9; ++i){
        for (j=1; j<=9; ++j)	  cout << i*j << '\t';
        cout << endl;
    }
}

