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

