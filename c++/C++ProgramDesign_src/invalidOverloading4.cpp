// ***************************************************************
// invalidOverloading4.cpp
// 函数重载时容易出现的错误演示4
// ***************************************************************
#include <iostream>
#include <cmath>
using namespace std;
double distance(float, float);
// 函数2原型：指定了默认参数
double distance(float, float, float x=0, float y=0);
int main()
{
    float point1X,point1Y;
    point1X = 5.0;
    point1Y = 5.0;
    cout << "The distance to the origin is: " <<endl;
    cout << "Point 1 (" << point1X << "," << point1Y << ")" << ":" 
	     << distance(point1X, point1Y) << endl;  // 出现二义性
    return 0;
}
// 函数1：求和原点的距离     
double distance(float posX, float posY)
{
    double dis;
    dis = sqrt(posX * posX + posY * posY);
    return dis;
}
// 函数2：求两点之间的距离
double distance(float pos1X, float pos1Y, float pos2X, float pos2Y)
{
    double dis;
    dis = sqrt((pos1X - pos2X) * (pos1X - pos2X) 
		        + (pos1Y - pos2Y) * (pos1Y - pos2Y));
    return dis;
}
