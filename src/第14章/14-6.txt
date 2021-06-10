　　//文件名：14-6.cpp
　　//设置精度的示例
　　#include <iostream>
　　#include <iomanip>
　　using namespace std;
　　
　　int main()
　　{   double x = 123.456789, y = 9876.54321;
　　 
　　    for (int i = 9; i > 0; --i) {
　　        cout.precision(i);
　　        cout << x << '\t' << y << endl;
　　    }
　　    //或写成for (int i = 9; i > 0; --i)  cout << setprecision(i) << x << '\t' << y << endl;
　　
　　    return 0;
     }
　　
