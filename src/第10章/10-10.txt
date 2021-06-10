//文件名：Rational.cpp
//函数的实现
#include "Rational.h"

//add函数将r1和r2相加，结果存于当前对象
void Rational::add(const Rational &r1, const Rational &r2)
{   num = r1.num * r2.den + r2.num * r1.den;
    den = r1.den * r2.den;
    ReductFraction();
}

//multi函数将r1和r2相乘，结果存于当前对象
void Rational::multi(const Rational &r1, const Rational &r2)
{    num = r1.num * r2.num;
    den = r1.den * r2.den;
    ReductFraction();
}

//ReductFraction实现有理数的化简
//方法：找出num和den的最大公因子，让它们分别除以最大公因子
void Rational::ReductFraction()
{   int tmp = (num > den) ? den : num;

    for (; tmp > 1; --tmp) 
	        if (num % tmp == 0 && den % tmp ==0) {num /= tmp; den /= tmp; break;}
}

