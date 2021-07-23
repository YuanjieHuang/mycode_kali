　　class Rational {
　　    friend Rational operator+(const Rational &r1, const Rational &r2); //+运算符重载
　　    friend Rational operator*(const Rational &r1, const Rational &r2); //*运算符重载
　　
　　private:  
　　    int num;
　　    int den;
　　
　　    void ReductFraction();
　　
　　public:
　　    Rational(int n = 0, int d = 1) { num = n; den = d; ReductFraction();}
　　    void display() { cout << num << '/' << den;}
　　};
　　
