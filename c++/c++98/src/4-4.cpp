//文件名：4-4.cpp
//计算无穷级数
#include <iostream>
using namespace std;

int main()
{   double ex, x, p;//ex存储ex的值，p保存当前项的值
    int i;
    
    cout << "请输入x：";
    cin >> x;
   
    ex=0;
    p=1;
    i=0;
 
    while (p>1e-6){
	      ex += p; 
        ++i;
        p = p * x / i;
    }

    cout << "e的" << x << "次方等于：" << ex << endl;
   
    return 0;
}

