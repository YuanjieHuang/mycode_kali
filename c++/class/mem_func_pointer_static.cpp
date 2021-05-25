
#include <iostream>
using namespace std;
 
class A{
public:
    
    //p1是一个指向非static成员函数的函数指针
    void (A::*p1)(void);
    
    //p2是一个指向static成员函数的函数指针
    void (*p2)(void);
    
    A(){
        /*对
         **指向非static成员函数的指针和指向static成员函数的指针
         **的变量的赋值方式是一样的，都是&ClassName::memberVariable形式
         **区别在于：
         **对p1只能用非static成员函数赋值
         **对p2只能用static成员函数赋值
         **再有，赋值时如果直接&memberVariable，则在VS中报"编译器错误 C2276"
         **参见：http://msdn.microsoft.com/zh-cn/library/850cstw1.aspx
         */
        p1 =&A::funa; //函数指针赋值一定要使用 &
        p2 =&A::funb;
        
        //p1 =&A::funb;//error
        //p2 =&A::funa;//error
        
        //p1=&funa;//error,编译器错误 C2276
        //p2=&funb;//error,编译器错误 C2276
    }
    
    void funa(void){
        puts("A");
    }
    
    static void funb(void){
        puts("B");
    }
};
 
int main()
{
    A a;
    //p是指向A中非static成员函数的函数指针
    void (A::*p)(void);
    (a.*a.p1)(); //打印 A
    
    //使用.*(实例对象)或者->*（实例对象指针）调用类成员函数指针所指向的函数
    p = a.p1;
    (a.*p)();//打印 A
    
    A *b = &a;
    (b->*p)(); //打印 A
    
    // 尽管a.p2本身是个非static变量,但是a.p2是指向static函数的函数指针，所以下面这就话是错的!
    // p = a.p2;//error
    (&A::funb)();
    void (*pp)(void);
    pp = &A::funb;
    pp(); //打印 B
    
    return 0;
}
