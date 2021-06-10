　　Rational operator+(const Rational &r1, const Rational &r2)
　　{   Rational tmp;
　　    tmp.num = r1.num * r2.den + r2.num * r1.den;
　　    tmp.den = r1.den * r2.den;
　　    tmp.ReductFraction();
　　    return tmp;
　　}
　　
　　Rational operator*(const Rational &r1,const Rational &r2)
　　{   Rational tmp;
　　    tmp.num = r1.num * r2.num;
　　    tmp.den = r1.den * r2.den;
　　    tmp.ReductFraction();
　　    return tmp;
　　}
　　
