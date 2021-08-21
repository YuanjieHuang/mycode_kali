//文件名：4-5.cpp
//水果问题求解
#include <iostream>
using namespace std;

int main()
{   int  mellon, apple, orange; 	//分别表示西瓜数、苹果数和橘子数
    for (mellon=1; mellon<10; ++mellon) 	//对每种可能的西瓜数
        for (apple=1; apple < 50 - 5 * mellon; ++apple) {	//当西瓜数给定后可能的苹果数
            orange = 3*(50-5*mellon-apple); 	//剩下的钱全买了橘子
           if (mellon+apple+orange == 100){ 	//3种水果数之和是否为100
              	cout << "mellon:" << mellon << ' ';
              	cout << "apple:" << apple << ' ';
              	cout << "orange:" << orange << endl; 
					}
       } 
    return 0;
}

