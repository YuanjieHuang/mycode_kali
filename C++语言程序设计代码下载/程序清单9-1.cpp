程序清单9-1
// ***************************************************************
// distanceOverloading.cpp
// 求距离的函数重载
// ***************************************************************

#include <iostream>
#include <cmath>						// 使用其中的平方根函数sqrt
using namespace std;

// 函数重载，函数名相同，但原型不同
double distance(float, float);		// 函数1原型，求一个点距原点的距离
// 函数2原型，求两点之间的距离
double distance(float, float, float, float); 

int main()
{
   	float point1X, point1Y, point2X, point2Y;

	point1X = 5.0;
	point1Y = 5.0;
	point2X = 7.0;
	point2Y = 7.0;

	cout << "The distance to the origin is: " <<endl;
	cout << "Point 1 (" << point1X << "," << point1Y << ")" << ":" 
		 << distance (point1X, point1Y) << endl; 	// 调用函数1
	cout << "Point 2 (" << point2X << "," << point2Y << ")" << ":" 
		 << distance(point2X, point2Y) << endl;  	// 调用函数1

	cout << "The distance between two points ("<< point1X << "," << point1Y
		 << ")" << "and ( " << point2X << "," << point2Y << ") is " 
		 << distance(point1X, point1Y, point2X, point2Y) << endl;// 调用函数2
 
	return 0;
}

double distance(float posX, float posY)
// 函数1：求指定点到原点的距离     
// 前置条件：posX posY 是点的坐标
// 后置条件：返回值为点(posX, posY)到原点的距离
{
    double dis;
    dis = sqrt(posX * posX + posY * posY);
    return dis;
}

double distance(float pos1X, float pos1Y, float pos2X, float pos2Y)
// 函数2：求两点之间的距离
// 前置条件：(pos1X, pos1Y),(pos2X, pos2Y)为两个点的坐标
// 后置条件：返回值为两点间的距离

{
     double dis;
     dis = sqrt((pos1X - pos2X) * (pos1X - pos2X) 
		          + (pos1Y - pos2Y) * (pos1Y - pos2Y));
     return dis;
}
