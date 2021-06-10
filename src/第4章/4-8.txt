//文件名：4-8.cpp
//贪婪法解硬币找零问题
#include<iostream>
using namespace std;

#define ONEFEN  1
#define TWOFEN  2
#define FIVEFEN  5
#define ONEJIAO  10

int main()
{   int money;
    int onefen = 0, twofen = 0, fivefen = 0, onejiao = 0;
  
     cout << "输入要找零的钱（以分为单位）：";  cin >> money;
  
     //不断尝试每一种硬币 
     while (money >= ONEJIAO) {onejiao++; money -= ONEJIAO;}
     while (money >= FIVEFEN) {fivefen++; money -= FIVEFEN;}
     while (money >= TWOFEN) {twofen++; money -= TWOFEN;}
     while (money >= ONEFEN) {onefen++; money -= ONEFEN;}

     //输出结果
     cout << "1角硬币数：" << onejiao << endl;
     cout << "5分硬币数：" << fivefen << endl;
     cout << "2分硬币数：" << twofen << endl;
     cout << "1分硬币数：" << onefen << endl;
  
     return 0;
}

