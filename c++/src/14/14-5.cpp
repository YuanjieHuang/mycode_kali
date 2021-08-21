　　//文件名：14-5.cpp
　　//设置整型数的基数的示例
　　#include <iostream>
　　#include <iomanip>
　　using namespace std;
　　
　　int main()
　　{   int n;
　　    cout << "Enter a octal number: "; //读入八进制表示的整型数
　　    cin >> oct >> n;
　　    cout << "octal " << oct << n << " in hexdecimal is:" << hex << n << '\n' ;
　　    cout << "hexdecimal " << n << " in decimal is:" << dec << n << '\n' ;
　　    cout << setbase(8) << "octal " << n <<" in octal is:" << n << endl;
　　    return 0;
　　 }
　　
