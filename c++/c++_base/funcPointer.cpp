#if 1
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//定义一个函数
int func(int a, int b) {
	cout << "a:" << a<< "    b:" << b << endl;

	return 0;
}


//定义一个函数指针
// C语言中 决定一个函数类型
// 返回值 参数列表

typedef int(FUNC)(int, int); //定义一个函数类型

typedef int(*FUNC_POINTER)(int, int); //定义一个函数指针类型


//如何将一个函数指针当成一个函数参数呢？
void my_function(FUNC *fp)
{
	fp(10, 20);
}

void my_function2(FUNC_POINTER fp)
{
	fp(10, 20);
}

//他是一个架构函数。 
void my_function3(int(*fp)(int, int), int a, int b)
{
	cout << "1999 年写的架构" << endl;
	cout << "固定业务1" << endl;
	fp(a, b);
	cout << "固定业务2" << endl;
}


//2015 实现一个子函数
int my_new_function(int a, int b)
{
	cout << a<< " my_new_function " << b << endl;
	cout << "2015年实现的新业务" << endl;

	return 0;
}

int main(void)
{
	FUNC * p = func;
	FUNC_POINTER p2 = func;
	int(*fp)(int, int) = func;

	// p(11, 20);
	// (*p)(10, 20); //以上两种写法等价

	// p2(30, 40);
	// (*p2)(20, 20);

	// fp(40, 20);

	// cout << " --------  " << endl;

	//2015   实现一个子函数，再调用1999的架构
	my_function3(my_new_function,20,30);
	
	return 0;
}
#endif
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
 
int AddFunc(int a, int b)  
{  
    return a + b;  
}  


class Add {
public:
    const int operator()(const int a,const int b){
        return a+b;
    }
};

int main() {
    //函数指针
    int (*Add1) (int a, int b);
    int (*Add2) (int a, int b);//两种函数指针赋初值方法，可以加取地址符也可以不加
    Add1 = &AddFunc;
    Add2 = AddFunc;               //两种函数指针赋初值方法
    cout << (*Add1) (3, 2)<<endl; // 5
    cout<<Add1 (3, 2)<<endl;      //输出可以加*，也可以不加
 
    //函数对象
    Add addFunction;
    cout<<addFunction(2, 3)<<endl;
    system("sleep 20");
    return 0;
}
