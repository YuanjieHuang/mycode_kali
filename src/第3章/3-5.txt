//文件名：3-5.cpp
//自动出题程序
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{   int num1, num2, op, result1, result2;//num1,num2:操作数，op:运算符，
      	//result1,result2:结果
 
    srand(time(NULL));  //随机数种子初始化

    num1 = rand() * 10 / (RAND_MAX + 1); //生成运算数
    num2 = rand() * 10 / (RAND_MAX + 1); //生成运算数
    op = rand() * 4 / (RAND_MAX + 1);    //生成运算符 0--+，1-- -，2--*，3-- /

    switch (op) {
        case 0: cout << num1 << "+" << num2 << "=?" ; cin >> result1;
                     if (num1+num2==result1)  cout << "you are right\n";
                         else  cout << "you are wrong\n";
                     break;
        case 1: cout << num1 << "-" << num2 << "=?" ; cin >> result1;
                     if (num1-num2==result1) cout << "you are right\n";
                         else  cout << "you are wrong\n";
                  break;
        case 2: cout << num1 << "*" << num2 << "=?" ; cin >> result1;
                     if (num1*num2==result1) cout << "you are right\n";
                         else  cout << "you are wrong\n";
                     break;
        case 3: cout << num1 << "/" << num2 << "=?" ; cin >> result1;
                cout << "余数为=?";  cin >> result2;
                     if ((num1/num2==result1)&&(num1%num2==result2))
                          cout << "you are right\n";
                          else  cout << "you are wrong\n";
                     break;
     }
 
     return 0;
}

