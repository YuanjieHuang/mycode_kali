#include "StaticSample.h"

int main()
{   
    StaticSample::display(); 	//通过类名限定调用静态成员函数

    StaticSample s1, s2;
    StaticSample::display();

    StaticSample *p1 = new StaticSample, *p2 = new StaticSample;
    s1.display(); 	//通过对象调用静态成员函数

    delete p1;
    p2->display(); 	//通过指向对象的指针调用静态成员函数

    delete p2;
    StaticSample::display();

    return 0;
}