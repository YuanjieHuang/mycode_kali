//文件名：8-1.cpp
//打印通讯录
#include <iostream>
#include <iomanip>
using namespace std;

struct personT
{   char name[10];
    char sex;
    char addr[30];
    int phonenum;
};
const int MAX = 100;

int main()
{   personT p[MAX];
    int i, num = 0;
                    
    cout << "姓名  性别  地址  电话（ @表示结束）：\n";
    while (num < 100) {
        cin >> p[num].name;
        if (p[num].name[0]=='@' ) break;
        cin >> p[num].sex >> p[num].addr >> p[num].phonenum;
        ++num;
    }
  
    cout << " Name  " << " Sex\t\t" << "Addr\t\t\t" << "PhoneNum\n";
    cout << setiosflags(ios::left);
    for (i=0; i<num; ++i)
        cout << setw(10) << p[i].name << p[i].sex << '\t' << setw(30)
             << p[i].addr << '\t' << p[i].phonenum << endl;
    return 0;
}

