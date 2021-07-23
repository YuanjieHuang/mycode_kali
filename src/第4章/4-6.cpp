//文件名：4-6.cpp
//求解四大湖问题
#include <iostream>
using namespace std;

int main()
{   int a, b, c, d;
    for (a=1; a<=4; ++a)
        for (b=1; b<=4; ++b)
             if ( a == b) continue; 		//洞庭湖和洪泽湖的排名不能并列
             else for (c=1; c<=4; ++c)
                      if (c==a||c==b) continue; 	//洞庭湖、洪泽湖和鄱阳湖的排名不能并列
                      else { d = 10 - a - b - c; 	//确定太湖的排名
                           if (((a==1)+(b==4)+(c==3))==1
                               &&((b==1)+(a==4)+(c==2)+(d==3))==1
                               &&((b==4)+(a==3))==1
                               &&((c==1)+(d==4)+(b==2)+(a==3))==1) 
                                   cout << "洞庭湖第" << a << "\t洪泽湖第" << b 
                                        << "\t鄱阳湖第" << c << "\t太湖第" << d << endl;
                       }
    return 0;
}

