#include "Rational.h"
using namespace std;

class Complex
{
    friend Complex operator+(const Complex &x, const Complex &y);
    friend istream& operator>>(istream &is, Complex &obj);
    friend ostream& operator<<(ostream &os, const Complex &obj);

    Rational real;  //实部
    Rational imag;  //虚部
public:
    Complex(int r1 = 0, int r2 = 1, int i1= 0, int i2 = 1):real(r1, r2), imag(i1, i2) {}
};

Complex operator+(const Complex &x, const Complex &y) //加法运算符重载
{   
    Complex tmp;
    tmp.real = x.real + y.real;   //利用Rational类的加法重载函数完成两个实部的相加
    tmp.imag = x.imag + y.imag;   //利用Rational类的加法重载函数完成两个虚部的相加
    return tmp;
}

istream& operator>>(istream &is, Complex &obj)   //输入运算符重载
{   cout << "请输入实部：";
    is >> obj.real;    //利用Rational类的输入重载实现实部的输入
    cout << "请输入虚部：";
    is >> obj.imag;   //利用Rational类的输入重载实现虚部的输入
    return is;
}

ostream& operator<<(ostream &os, const Complex &obj)   //输出运算符重载
{ 
    //利用Rational类的输出重载实现实部和虚部的输出
    cout << '(' << obj.real << " + " << obj.imag << "i" << ')'; 
    return os;
}

int main()
{	
    Complex x1,x2,x3;

 	cout << "请输入x1：\n"; cin >> x1;   //利用输入重载输入复数x1
 	cout << "请输入x2:  \n"; cin >> x2;  //利用输入重载输入复数x2

 	x3 = x1 + x2;   //利用加运算符重载完成加法
 	cout << x1 << " + " << x2 << " = " << x3 << endl;   //利用输出重载输出复数

 	return 0;
}