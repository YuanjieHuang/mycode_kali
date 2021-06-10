//文件名：4-7.cpp
//四大湖问题的改进版 
#include <iostream>
using namespace std;

int main()
{   int a, b, c, d;
    bool flag = false;
    for (a=1; a<=4 && !flag; ++a)
        for (b=1; b<=4 && !flag; ++b)
            if (a == b) continue;
            else for (c=1; c<=4 && !flag; ++c)
                     if (c==a||c==b) continue;
				            else { d = 10 - a - b - c;
	                       if (((a==1)+(b==4)+(c==3))==1
		                          &&((b==1)+(a==4)+(c==2)+(d==3))==1
	  	                          &&((b==4)+(a==3))==1
		                          &&((c==1)+(d==4)+(b==2)+(a==3))==1) {
			                      cout << "洞庭湖第" << a << "\t洪泽湖第" << b 
                                  << "\t鄱阳湖第"<< c <<"\t太湖第" << d << endl;
					                  flag = true;
				                 }
		                 }
    return 0;
}

