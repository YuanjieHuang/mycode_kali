#ifndef _StaticSample_h
#define _StaticSample_h
#include <iostream>
using namespace std;

class StaticSample {
private:
      static int obj_count; 
      static int obj_living;
public:
      StaticSample() {++obj_count; ++obj_living;}
      ~StaticSample() {--obj_living;}
      static void display() 	//静态成员函数
        {cout << "总对象数：" << obj_count << "\t存活对象数：" << obj_living << endl;}
};
int StaticSample::obj_count = 0;	//静态数据成员的定义及初始化
int StaticSample::obj_living = 0; 	//静态数据成员的定义及初始化
#endif