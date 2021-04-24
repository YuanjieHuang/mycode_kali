#include <iostream>
#include <vector>
#include <memory>
// #include "MyDelegate.h"
// using namespace Delegate;
using namespace std;
#if 0
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
int _tmain(int argc, _TCHAR* argv[])
{
	//首先创建了一个返回值为 void ,参数为int 的一个委托。
	CMultiDelegate<void, int> e;
	//将三个函数注册到该委托中
	e += newDelegate(NormalFunc);
	e += newDelegate(A::StaticFunc);
	e += newDelegate(&A(), &A::MemberFunc);
	//调用
	e(1);
	return 0;
}
#endif
void DoSomething()
{
    vector＜CTestObj*＞vec_objs;
    for(int i=0;i=OBJECTS_COUNT;i++)
    {
        vec_objs.push_back(new CTestObj);
    }
    …//use vec_objs to do something
}
void DoSomething()
{
    vector＜CTestObj*＞vec_objs;
    for(int i=0;i=OBJECTS_COUNT;i++)
    {
        vec_objs.push_back(new CTestObj);
    }
    …//use vec_objs to do something
    vector＜CTestObj*＞::iterator it=vec_objs.begin();
    for(;it!=vec_objs.end();++it)
    {
        delete*it;
    }
}
void DoSomething()
{
typedef boost::shared_ptr＜CTestObj＞SmartTestPtr;
vector＜SmartTestPtr＞vec_objs;
for(int i=0;i=OBJECTS_COUNT;i++)
{
vec_objs.push_back(SmartTestPtr(new CTestObj));
}
…//use vec_objs to do something
}