　　//文件名：14-10.cpp
　　//读有各种类型数据的文件的示例
　　#include <fstream>
　　#include <iostream>
　　using namespace std;
　　
　　int main()
　　{   ifstream fin("test");
　　    char s[80];
　　    int i;
　　    float x;
　　
　　    if (!fin) {cout << "cannot open input file\n"; return 1;}
　　    fin >> i >> x >> s; cout << i << " " << x << s;
　　    fin.close(); 
　　 
　　    return 0; 
　　}
　　
