　　//文件名：Rational.h
　　//Rational类的完整定义
　　#ifndef _rational_h
　　#define _rational_h
　　#include <iostream.h>
　　
　　class Rational {
　　      friend istream& operator>>(istream &in, Rational& obj);       //输入重载函数
　　      friend ostream& operator<<(ostream &os, const Rational& obj); //输出重载函数
　　      friend Rational operator+(const Rational &r1, const Rational &r2); //+运算符重载
　　      friend Rational operator*(const Rational &r1, const Rational &r2); //*运算符重载
　　
　　private:  
　　      int num;
　　      int den;
　　
　　      void ReductFraction();
　　
　　public:
　　      Rational(int n = 0, int d = 1) { num = n; den = d; ReductFraction();}
　　      operator double () const { return (double(num)/den);}
　　
　　};
　　#endif
　　
