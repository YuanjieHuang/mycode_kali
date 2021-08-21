#ifndef _rational_h
#define _rational_h
#include <iostream>
using namespace std;
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
      operator double () const { return (double(num)/den);}//???????????????????
};

void Rational::ReductFraction() //化简有理数
{
    int tmp = (num > den) ? den : num;
    for  (; tmp > 1; --tmp)   
        if (num % tmp == 0 && den % tmp ==0) {num /= tmp; den /= tmp; break;}
}

istream& operator>>(istream &in, Rational& obj) //输入重载函数
{ 
    in >> obj.num >> obj.den;
    obj.ReductFraction();
    return in;
}

ostream& operator<<(ostream &os, const Rational& obj) //输出重载函数
{
    os << obj.num << '/' << obj.den;
    return os;
}

Rational operator+(const Rational &r1, const Rational &r2)
{   
    Rational tmp;
    tmp.num = r1.num * r2.den + r2.num * r1.den;
    tmp.den = r1.den * r2.den;
    tmp.ReductFraction();
    return tmp;
}

Rational operator*(const Rational &r1,const Rational &r2)
{   
    Rational tmp;
    tmp.num = r1.num * r2.num;
    tmp.den = r1.den * r2.den;
    tmp.ReductFraction();
    return tmp;
}

#endif