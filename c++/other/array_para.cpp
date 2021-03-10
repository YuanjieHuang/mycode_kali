/*
·数组元素作实参，与单个变量一样。
·数组名作参数形、实参数都应是数组名(实质上是地址，关于地址详见6.2)，
类型要一样，传送的是数组首地址。对形参数组的改变会直接影响到实参数组。
可以定义为常数组，则不会改变函数的参数


*/

#include <iostream>
using namespace std;

void RowSum(int A[][4], int nrow)    //计算二维数组A每行元素的值的和，nrow是行数
{
	for (int i = 0; i < nrow; i++)
	{
		for (int j = 1; j < 4; j++)
			A[i][0] += A[i][j];
	}
}
int main(void)	//主函数
{
	int Table[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };	//声明并初始化数组
	for (int i = 0; i < 3; i++)	//输出数组元素
	{
		for (int j = 0; j < 4; j++)
			cout << Table[i][j] << "   ";
		cout << endl;
	}
	RowSum(Table, 3);	//调用子函数，计算各行和
	for (int i = 0; i < 3; i++)	//输出计算结果
	{
		cout << "Sum of row " << i << " is " << Table[i][0] << endl;
	}
	return 0;
}
