　　Rational Rational::operator+(const Rational &r1)
　　{   Rational tmp;
　　
　　    tmp.num = num * r1.den + r1.num * den;
　　    tmp.den = den * r1.den;
　　    tmp.ReductFraction();
　　
　　    return tmp;
　　}
　　
　　Rational Rational::operator*(const Rational &r1)
　　{   Rational tmp;
　　
　　    tmp.num = num * r1.num;
　　    tmp.den = den * r1.den;
　　    tmp.ReductFraction();
　　
　　   return tmp;
　　}
　　
