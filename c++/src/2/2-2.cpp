//文件名: circle.cpp
//计算圆的面积和周长

#define  PI 3.14159 //定义符号常量
#include <iostream> 
using namespace std;

int main()
{   double radius, area, circum;  

    cout << "请输入圆的半径：" ; 
    cin >> radius; 

    area = PI * radius * radius;
    circum = 2 *  PI *  radius;

    cout << endl;
    cout << "圆的面积为：" << area << endl;
    cout << "圆的周长为：" << circum << endl;

    return 0;
}

