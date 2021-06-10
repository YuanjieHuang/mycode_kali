//文件名：7-5.cpp
//求几个正整数的平均值
#include <iostream>
using namespace std;

int ConvertStringToInt(char *); 

int main(int argc, char *argv[])
{   int sum = 0;
    for (int i = 1; i < argc; ++i) sum += ConvertStringToInt(argv[i]);
    cout << sum / (argc - 1) << endl;
    return 0;
}

//将字符串转换成整型数
int ConvertStringToInt(char *s)
{   int num = 0;
     while(*s) {num = num * 10 + *s - '0'; ++s;}
    return num;
}

