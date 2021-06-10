程序清单3-6
//**********************************************************
// Numbers Comparison Program
// This program determines the median of three input numbers.
//**********************************************************
#include <iostream>;
using namespace std
int main()
{
	float a,b,c;	// a,b,c三个数据
	float median;	// 中间数
	float max,	// 较大的数
	float min; 	// 较小的数
	bool dataAreOK;	// 三个数据互不相同则为true
	// 提示输入数据
	cout << "Please enter three different numbers. " << endl;      
	cin >> a >> b >> c;                                       
	// 测试输入数据
	if (a==b || b==c || a==c)
		dataAreOK = false;
	else 
		dataAreOK = true;
	if (dataAreOK)	{ 
          // 比较数据
	     if (a>b)                                            
		    max=a , min=b;
	     else max=b , min=a;
	     if (max<c)
		    median=max;
	     else if (min>c) 
		    median=min;
	     else 
		    median=c;
          // 打印结果
	     cout << "The median of " << a << ", " << b << ", and " << c; 
	     cout << " is " << median << "." << endl;
	else
	cout << "The numbers you inputed are invalid." << endl;
	return 0;
}
