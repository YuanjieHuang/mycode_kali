//文件名：10-16.cpp
//Girl类的定义及使用
#include <iostream>
#include <cstring>
using namespace std;
　　
class Girl {
    friend void disp(Girl &x); 
private:
    char name[10];
    int age;
public:
    Girl(char *n, int d)  {strcpy(name,n);  age=d;}  
};
　　
void disp(Girl &x)  {cout<<x.name<<"  "<<x.age<<endl;} //友元函数的定义
　　
int main()
{   Girl e("abc", 15);  
    disp(e); 
　　
    return 0;
}
　　
