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
　　
