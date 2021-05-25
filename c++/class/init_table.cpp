#include <iostream>
using namespace std;

// class Test
// {
//  public:
//     Test (int, int, int)
//     {
//         cout <<"Test" << endl;
//     };
//  private:
//     int x;
//     int y;
//     int z;
// };
// class Mytest
// {
//  public:
//     Mytest():test(1,2,3)
//     {
//         //初始化  
//         cout << "Mytest" << endl;
//     };
// private:
//     Test test; //声明  
// }; 

class Test{
public:
    Test(){ cout << "111111111";};
    Test (int x){ int_x = x;};
    void show(){cout<< int_x << endl;}
private:
    int int_x;
};
class Mytest:public Test{
public:
    Mytest() :Test(110)
    {
        // 构造函数只能在初始化列表中被显示调用(如果不显示初始化，默认调用默认构造函数)，不能在构造函数内部被显示调用
        // 内部调用的是临时变量
        // Test(110);            
    };
}; 
int main()
{
 Test *p = new Mytest();
 p->show();
 return 0;
}
// int main()
// {
//     // Mytest test;
//     return 0;
// }