//demo.h
#ifndef _DEMO_H
#define _DEMO_H
extern const int num;  //声明 const 常量
#endif
//demo.cpp
#include "demo.h"   //一定要引入该头文件
const int num =10;  //定义 .h 文件中声明的 num 常量
//main.cpp
#include <iostream>
#include "demo.h"
int main() {
    std::cout << num << std::endl;
    return 0;
}

//demo.cpp
extern const int num =10;
//main.cpp
#include <iostream>
extern const int num;
int main() {
    std::cout << num << std::endl;
    return 0;
}