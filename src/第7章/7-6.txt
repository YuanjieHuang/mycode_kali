//文件名：7-6.cpp
//用指向指针的指针访问指针数组
#include <iostream>
using namespace std;

int main()
{   char  **p, *city[] = {"aaa", "bbb", "ccc", "ddd",  "eee"};
    for (p = city; p < city + 5; ++p)     cout << *p << endl;
    return 0;
}

