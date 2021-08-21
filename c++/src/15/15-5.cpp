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
　　
