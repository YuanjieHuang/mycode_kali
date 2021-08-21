#include <iostream>
using namespace std;

class Rational {
private:
    int num; 
    int den;
    void ReductFraction();
public:
    Rational(int n = 0, int d = 1) { num = n; den = d; ReductFraction();}
    Rational operator+(const Rational &r1); //+运算符重载
    Rational operator*(const Rational &r1);//*运算符重载
    void display() { cout << num << '/' << den;}
};

void Rational::ReductFraction() //化简有理数
{
    int tmp = (num > den) ? den : num;
    for  (; tmp > 1; --tmp)   
        if (num % tmp == 0 && den % tmp ==0) {num /= tmp; den /= tmp; break;}
}
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

int main()
{   
    Rational r1(1,6), r2(1,6), r3;

    r3 = r1 + r2;  //r3 = r1.operator+(r2)
    r1.display(); cout << " + "; r2.display(); cout << " = "; r3.display(); cout << endl;

    r3 = r1 * r2;  //r3 = r1.operator*(r2)
    r1.display(); cout << " * "; r2.display(); cout << " = "; r3.display(); cout << endl;

    return 0;
}