#include <iostream>
using namespace std;
template <class... T>
void f(T... args)
{    
    cout << sizeof...(args) << endl; //打印变参的个数
}

// int main()
// {
//     f();        //0
//     f(1, 2);    //2
//     f(1, 2.5, ""); 
//     return 0;
// }

//递归终止函数
void print()
{
   cout << "empty" << endl;
}
//展开函数
template <class T, class ...Args>
void print(T head, Args... rest)
{
   cout << "parameter " << head << endl;
   print(rest...);
}


int main(void)
{
   print(1,2,3,4);
   return 0;
}
// 逗号表达式和初始化列表
template <class T>
void printarg(T t)
{
   cout << t << endl;
}

template <class ...Args>
void expand(Args... args)
{
   int arr[] = {(printarg(args), 0)...};
   //将会展开成((printarg(arg1),0), (printarg(arg2),0), (printarg(arg3),0),  etc... )，
//    最终会创建一个元素值都为0的数组int arr[sizeof...(Args)]。
}

expand(1,2,3,4);