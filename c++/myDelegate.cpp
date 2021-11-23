#include "MyDelegate.h" 
#include<stdio.h> 
using namespace Delegate;  
  
void NormalFunc(int a)  
{  
    printf("这里是普通函数 ：%d\n", a);  
}  
  
class A  
{  
public:  
    static void StaticFunc(int a)  
    {  
        printf("这里是成员静态函数 ： %d\n", a);  
    }  
    void MemberFunc(int a)  
    {  
        printf("这里是成员非静态函数 ： %d\n", a);  
    }  
};  
int main()  
{  
    //首先创建了一个返回值为 void ,参数为int 的一个委托。  
    CMultiDelegate<void, int> e;  
    A a;
    //将三个函数注册到该委托中  
    e += newDelegate(NormalFunc);  
    e += newDelegate(A::StaticFunc);  
    e += newDelegate(&a, &A::MemberFunc);  
  
    //调用  
    e(1);  
  
    return 0;  
} 

/*
#include<iostream>
using namespace std;
 
template<typename Head, typename ...Tail>
double Max(Head first, Tail... rest)
{
	double Maxnum=0;
	Maxnum = Max(rest...);
	if (Maxnum < first)
		Maxnum = first;
	return Maxnum;
}
template<typename Head>
double Max(Head first)
{
	return first;
}
 
int main()
{
	cout << Max(1, 3, 3.4, 5.1, 1.5);
}


// 模板类是通过私有继承来实现递归的
template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...>{
	Head head;
public:
// implementation
};
template<typename Head>
class tuple<Head> {
    // implementation
};


*/