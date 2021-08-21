　　//文件名：14-4.cpp
　　//read和gcount函数的应用示例
　　#include <iostream>
　　using namespace std;
　　int main()
　　
　　{   char buffer[ 80 ];
　　    cout << "Enter a sentence:\n";
　　    cin.read(buffer, 20);
　　    cout << "\nThe sentence entered was:\n";
　　    cout.write(buffer, cin.gcount());
　　    cout << endl;
　　    cout << "一共输入了" << cin.gcount() << "个字符\n";
　　    return 0;
     }
　　
