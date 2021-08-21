　　//文件名：15-7.cpp
　　//抛出指定异常的函数示例
　　#include <iostream>
　　using namespace  std;
　　class up{};
　　class down{};
　　void f(int i) throw(up, down);		//f函数可能抛出两类异常：up和down
　　
　　int main()
　　{   for (int i=1;i<=3;++i)   try { f(i); }
　　        catch (up) {cout << "up catched" << endl; }
　　        catch (down) {cout << "down catched" << endl;}
　　    return 0;
　　}
　　
　　void f(int i) throw(up,down)
　　{   switch(i) {
　　        case 1: throw up();
　　        case 2: throw down();
　　    }
　　}
　　
