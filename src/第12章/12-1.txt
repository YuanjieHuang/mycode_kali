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
　　
