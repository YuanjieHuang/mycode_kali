//文件名：8-2.cpp
//对平面上点的操作的函数及应用
#include <iostream>
#include <cmath>
using namespace std;
struct pointT{
    double x,y;
};

pointT setPoint(double x, double y)
{   pointT p;

    p.x = x;
    p.y = y;

    return (p);
}

    double getX(const pointT &p)
{
    return (p.x);
}

    double getY(const pointT &p)
{
    return (p.y);
}

    void showPoint(const pointT &p)
{
    cout << "(" << p.x << " , " << p.y << ")";
}

double distancePoint(const pointT &p1, const pointT &p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}

int main()
{   pointT p1, p2;

    p1 = setPoint(1,1);
    p2 = setPoint(2,2);

    cout << getX(p1) << "  " << getY(p2) << endl; 
    showPoint(p1);
    cout << " -> " ;
    showPoint(p2);
    cout << " = " << distancePoint(p1, p2) << endl;

    return 0;
}