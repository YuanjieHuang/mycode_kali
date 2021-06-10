　　Complex operator+(const Complex &x, const Complex &y) //加法运算符重载
　　{   Complex tmp;
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
　　
