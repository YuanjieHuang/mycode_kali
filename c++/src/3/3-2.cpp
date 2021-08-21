//文件名：3-2.cpp
//求一元二次方程解
#include <iostream>
#include <cmath>           //sqrt所属的库
using namespace std;

int main()
{   float a, b, c, x1, x2, dlt;

    cout << "请输入3个参数：" << endl;
    cout << "输入 a:";   cin >> a ;
    cout << "输入 b:";   cin >> b ;
    cout << "输入 c:";   cin >> c ;

    if (fabs(a) < 1e-6)  cout << "不是一元二次方程" << endl; //fabs(a)<1e-6判a是否为0
    else {
       dlt = b * b - 4 * a * c;
       if (dlt >= 0) {       //有实根
             x1 = (-b + sqrt(dlt)) / 2 / a; 
             x2 = (-b - sqrt(dlt)) / 2 / a; 
             cout << "x1=" << x1 << "   x2=" << x2 << endl; 
        }
        else cout << "无根" << endl;       //无实根
    }
    return 0;
}

