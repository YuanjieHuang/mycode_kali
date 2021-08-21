　　//文件名：14-8.cpp
　　//文件的顺序读写
　　#include <iostream>
　　#include <fstream>		//使用文件操作必须包含fstream
　　using namespace std;
　　
　　int main()
　　{   ofstream out("file");	//定义输出流，并与文件file关联
　　    ifstream in;			//定义一个输入流对象
　　    int i;
　　
　　    if (!out) {cerr << "create file error\n"; return 1;}	//如打开文件不成功，则返回
　　    for (i = 1; i <= 10; ++i) out << i << ' ';			//将1～10写到输出流对象
　　    out.close();
　　
　　    in.open("file");									//重新以输入方式打开文件file
　　    if (!in) {cerr << "open file error\n"; return 1;}
　　    while (in >> i) cout << i << ' ';					//读文件，直到遇到文件结束
　　    in.close();
　　
　　    return 0;
　　}
　　
