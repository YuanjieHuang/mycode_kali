#include <string>
#include <iostream>
using namespace std;

/*
函数指针用做函数返回值的类型。
 //without typedef
int (*func(int*, int))(const string&, const string&);
上面的声明，将func(int*, int)声明为一个函数，返回值为函数指针，函数类型为int (*)(const string&, const string&)。
如果写成typedef就不用这么纠结了，足见typedef的作用：
typedef int (*CompareFunctionType)(const string&, const string&);
CompareFunctionType func(int*, int);
*/
 

int (*func(int*, int))(const string&, const string&);

typedef int (*CompareFunctionType)(const string&, const string&);
CompareFunctionType func(int*, int);

 extern "C" int InsideFunctionC(const string& str1, const string& str2)
 {
     return str1.compare(str2);
 }
 
 int InsideFunctionCPlusPlus(const string& str1, const string& str2)
 {
     return str1.compare(str2); 

 }


 int (*CompareFunction)(const string&, const string&) = InsideFunctionC;
 extern "C" void OutSideFunction(int (*fc)(const string&, const string&))
 {
     cout<<fc("abc", "abc")<<endl;;
 }

 int main()
 {
     OutSideFunction(InsideFunctionC);
     OutSideFunction(InsideFunctionCPlusPlus);
     
     return 0; 

 }