#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


// 非静态成员指针

// 类成员变量指针，实际上并不是真正意义上的指针，即它并不是指向内存中某个地址，而是该成员变量与对象指针的偏移量。
// 该偏移量只有附着在某个具体对象，才能指向对象成员变量的具体地址。
class A
{
public:
	A(int a=0,int b=0):a(a),b(b){}
	void print()
	{
		cout<<"a="<<a<<"  "<<"b="<<b<<endl;
	}
public:
	int a;
	int b;
};
typedef void (A::*pFunA)(void);
int test_non_static_mem_data(void)
{
	A ap;
	ap.print();//输出a和b的默认值
	int A::*aptr=&A::a;//aptr为A这个类中，a的成员指针
	int A::*bptr=&A::b;////aptr为A这个类中，b的成员指针
	printf("aptr=%d,bptr=%d\n",aptr,bptr);//输出两个指针值
	ap.*bptr=5;//通过成员指针修改成员的值
	ap.print();
	return 0;
}


// 静态成员

// 对于C++静态成员的指针，其值就是指向内存中数据区某个地址，就是真正意义上的指针，因为静态成员属于类范围，不属于某个对象。
class B
{
public:
	B(){}
	void print()
	{
		cout<<"a="<<a<<endl;
	}
public:
	 static int a;
};
int B::a=1;
typedef void (B::*pFunB)(void);
int test_static_mem_data(void)
{
	const int *p=&B::a;
	printf("p=%p\n",p);
	return 0;
}

int main()
{
    test_static_mem_data();
    return 0;
}