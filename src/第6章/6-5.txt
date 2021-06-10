//文件名：6-5.cpp
//用内联函数打印平方表和立方表
#include <iostream>
using namespace std;

inline square(int x) {return x*x;}
inline cube(int x) {return x*x*x;}

int main()
{   int i;

    cout << "x" << '\t' << "x*x" << '\t' << "x*x*x" << endl;
    for (i=1; i<=100; ++i) cout << i << '\t' << square(i) << '\t' << cube(i) << endl;

    return 0;
}

