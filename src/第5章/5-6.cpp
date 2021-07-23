//文件名：5-6.cpp
//冒泡排序
#include <iostream>
using namespace std;

int main()
{   int a[ ] = { 0, 3, 5, 1, 8, 7, 9, 4, 2, 10, 6};
    int i, j, tmp, n = 11;
    bool flag; //记录一趟起泡中有没有发生过交换

    for (i=1; i<n; ++i)
    {   flag = false;
        for (j=0; j<n-i; ++j)
            if (a[j+1] < a[j])
                {tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp; flag = true;}
        if (!flag) break; //一趟起泡中没有发生交换，排序结束
    }

    cout << endl;
    for (i=0; i<n; ++i)  cout << a[i] << ' ';

    return 0;
}

