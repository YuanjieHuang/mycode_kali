　　//文件名：14-7.cpp
　　//用户的定义流操纵符示例
　　#include <iostream>
　　using namespace std;
　　
　　ostream &tab(ostream &os) {return os <<'\t';}
　　
　　int main()
　　{   int a=5,b=7;
　　
　　    cout << a << tab << b <<endl;
　　
　　    return 0;
　　}
　　
