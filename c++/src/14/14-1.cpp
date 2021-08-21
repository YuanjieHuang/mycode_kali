

 <iostream>
 namespace std;
 main()
   int a = 5, *p = &a;
    double x = 1234.56;
    char ch = 'a';
    cout << "a = " << a << endl;	//输出整型变量a的值
    cout << "x = " << x << endl;	//输出双精度变量x的值
    cout << "ch = " << ch << endl;	//输出字符型变量ch的值
    cout << "*p = " << *p << endl;	//输出整型指针p指向的空间中的值
    cout << "p = " << p << endl;	//输出整型指针p的值，即一个地址
    return 0;

