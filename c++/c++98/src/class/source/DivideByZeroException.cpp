　　//类DivideByZeroException是用户定义的类，用于表示除0错
　　class DivideByZeroException {
　　public:
　　    DivideByZeroException(): message( "attempted to divide by zero" ) { }
　　    const char *what() const { return message; }
　　private:
　　    const char *message;
　　};
　　
　　double div(int x, int y)
　　{ if (y == 0)  throw  DivideByZeroException();
　　
　　    return static_cast< double > (x) / y;
　　}
　　
　　int div(int x, int y)
　　{   if (y==0) throw y;
　　    return x/y;
　　}
　　
　　//文件名：15-4.cpp
　　//带有异常检测的除法程序
　　int main()
　　{   int number1, number2;
　　    double result;
　　    cout << "Enter two integers (end-of-file to end): ";
　　    while (cin >> number1 >> number2) {
　　        try { 
　　            if (number2 == 0)  throw DivideByZeroException();
　　            result =  static_cast< double > (number1) / number2;
　　            cout << "The quotient is: " << result << endl;
　　        } 
　　        catch ( DivideByZeroException ex) {
　　            cout << "Exception occurred: " << ex.what()  << '\n';   }
　　            cout << "\nEnter two integers (end-of-file to end): ";
　　        }
　　    cout << endl;
　　    return 0;
　　}
　　
　　//文件名：15-5.cpp
　　//抛出异常的函数的应用
　　int main()
　　{   int number1, number2;
　　    double result;
　　    cout << "Enter two integers (end-of-file to end): ";
　　    while ( cin >> number1 >> number2 ) {
　　        try { result = div(number1, number2);
　　            cout << "The quotient is: " << result << endl;
　　        } 
　　        catch (DivideByZeroException ex) {
　　            cout << "Exception occurred: "<< ex.what() << '\n'; }
　　        cout << "\nEnter two integers (end-of-file to end): ";
　　    }
　　    cout << endl;
　　    return 0;
　　}
　　
　　int main()
　　{   try {
　　        cout << div(6, 3) << endl;
　　        cout << div(10, 0) << endl;
　　        cout << div(5, 2) << endl;
　　        }
　　    catch (int) {cout << "divide by zero" << endl; }
　　    cout << "It’s Over" << endl;
　　    return 0;
　　}
　　
　　//文件名：15-7.cpp
　　//抛出指定异常的函数示例
　　#include <iostream>
　　using namespace  std;
　　class up{};
　　class down{};
　　void f(int i) throw(up, down);		//f函数可能抛出两类异常：up和down
　　
　　int main()
　　{   for (int i=1;i<=3;++i)   try { f(i); }
　　        catch (up) {cout << "up catched" << endl; }
　　        catch (down) {cout << "down catched" << endl;}
　　    return 0;
　　}
　　
　　void f(int i) throw(up,down)
　　{   switch(i) {
　　        case 1: throw up();
　　        case 2: throw down();
　　    }
　　}
　　
