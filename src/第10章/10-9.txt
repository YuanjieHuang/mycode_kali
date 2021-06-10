//文件名：Rational.h
//有理数类
#ifndef rational_h
#define rational_h

#include <iostream>
using namespace std;

class Rational {
private:
    int num; 				//分子 
    int den; 				//分母

    void ReductFraction(); //将有理数化简成最简形式

public:
    void create(int n, int d) { num = n; den = d; ReductFraction()}
    void add(const Rational &r1, const Rational &r2);	//r1+r2,结果存于当前对象
    void multi(const Rational &r1, const Rational &r2);	//r1*r2,结果存于当前对象
    void display() { cout << num << '/' << den;}
};

#endif

