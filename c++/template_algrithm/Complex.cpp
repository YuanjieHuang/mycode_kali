class Complex {
 //类的声明
protected:
    double realpart;
    double imagpart;
public：
    Complex();
    Complex(double realVal, double imagVal);
    Complex(Complex& z){ assign(z); }
    ~Complex();
    void assign(Complex& z);
    double getReal(void) const { return realpart; }
    double getImag(void) const { return imagpart; }
    friend Complex add(Complex& z1, Complex& z2);
};

//类的实现
Complex::Complex(double realVal, double imagVal)
{
    realpart = realVal;
    imagpart = imagVal;
}

void Complex::assign(Complex& z)
{
    realpart = z.realVal;
    imagpart = z.imagVal;
}

Complex add(Complex& z1, Complex& z2);
{
     Complex sum(z1);
     sum.realpart = z2.realVal;
     sum.imagpart = z2.imagVal;
     return sum;
}
