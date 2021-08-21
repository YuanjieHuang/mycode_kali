　　//文件名：14-19.cpp
　　//字符串流的使用示例
　　#include <iostream>
　　#include <sstream>
　　#include <string>
　　using namespace std;
　　
　　int main()
　　{   string ch;
　　    ostringstream os(ch);				//或ostringstream os; 定义一个字符串流类的对象
　　
　　    for (int i = 0; i<=20; ++i) os << i << ' ';	//将1～20写入os
　　    cout << os.str();					//显示写入os的内容，为1～20，数字间用空格分开
　　    cout << endl;
　　
　　    istringstream is(os.str());		//用os对应的字符串初始化输入流is
　　
　　    while (is >> i) cout << i << '\t';	//从输入流读数据，直到输入流结束
　　
　　    return 0;
　　}
　　
