　　//文件名：12-3.cpp
　　//Complex类的使用
　　int main()
　　{	Complex x1,x2,x3;
　　
　　 	cout << "请输入x1：\n"; cin >> x1;   //利用输入重载输入复数x1
　　 	cout << "请输入x2:  \n"; cin >> x2;  //利用输入重载输入复数x2
　　
　　 	x3 = x1 + x2;   //利用加运算符重载完成加法
　　 	cout << x1 << " + " << x2 << " = " << x3 << endl;   //利用输出重载输出复数
　　
　　 	return 0;
　　}
　　
