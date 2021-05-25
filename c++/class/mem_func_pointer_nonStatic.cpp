/*
声明：与普通函数作为区分，指向类的成员函数的指针只需要在指针前加上类类型即可，格式为：
typedef 返回值 (类名::*指针类型名)(参数列表);

赋值：只需要用类的成员函数地址赋值即可，格式为：
指针类型名  指针名 = &类名::成员函数名;
注意：这里的这个&符号是比较重要的：不加&，编译器会认为是在这里调用成员函数，所以需要给出参数列表，否则会报错；
加了&，才认为是要获取函数指针。这是C++专门做了区别对待。

调用：调用方法也很简单，针对调用的对象是对象还是指针，分别用.*和->*进行调用，格式为：
(类对象.*指针名)(参数列表);
(类指针->*指针名)(参数列表);

*/
#include <iostream>
#include <cstdio>
using namespace std;
 

int test0(int a)
{
    return a;
}
 
int main00(int argc, const char * argv[])
{
    
    typedef int (*fp)(int a);
    fp f = test0;
    cout<<f(2)<<endl;
    return 0;
}


int test(int a)
{
    return a-1;
}
int test2(int (*fun)(int),int b)
{
    
    int c = fun(10)+b;
    return c;
}
 
int main01(int argc, const char * argv[])
{
    
    typedef int (*fp)(int a);
    fp f = test;
    cout<<test2(f, 1)<<endl; // 调用 test2 的时候，把test函数的地址作为参数传递给了 test2
    return 0;
}


class A
{
    public:
        A(int aa = 0):a(aa){}
 
        ~A(){}
 
        void setA(int aa = 1)
        {
            a = aa;
        }
        
        virtual void print()
        {
            cout << "A: " << a << endl;
        }
 
        virtual void printa()
        {
            cout << "A1: " << a << endl;
        }
    private:
        int a;
};
 
class B:public A
{
    public:
        B():A(), b(0){}
        
        B(int aa, int bb):A(aa), b(bb){}
 
        ~B(){}
 
        virtual void print()
        {
            A::print();
            cout << "B: " << b << endl;
        }
 
        virtual void printa()
        {
            A::printa();
            cout << "B: " << b << endl;
        }
    private:
        int b;
};
 
int main(void)
{
    A a;
    B b;
    void (A::*ptr)(int) = &A::setA;
    A* pa = &a;
    
    //对于非虚函数，返回其在内存的真实地址
    printf("A::set(): %p\n", &A::setA);

    //对于虚函数， 返回其在虚函数表的偏移位置
    printf("B::print(): %p\n", &A::print);
    printf("B::print(): %p\n", &A::printa);
 
    a.print();
    a.setA(10);
    a.print();
    a.setA(100);
    a.print();
    
    // 使用 .* (实例对象)或者 ->*（实例对象指针）调用类成员函数指针所指向的函数 
    //对于指向类成员函数的函数指针，引用时必须传入一个类对象的this指针，所以必须由类实体调用
    (pa->*ptr)(1000);
    a.print();
    (a.*ptr)(10000);
    a.print();
    return 0;
}