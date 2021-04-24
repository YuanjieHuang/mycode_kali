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

int char_array(void)
{
	char key[] = { 'a','c','b','a','d' };
	char c;
	int ques = 0, numques = 5, numcorrect = 0;
	cout << "Enter the " << numques << " question tests:" << endl;
	while (cin.get(c))		
	{
		if (c != '\n')
			if (c == key[ques])
			{
				numcorrect++;
				cout << " ";
			}
			else	cout << "*";
		else
		{
			cout << " Score " << float(numcorrect) / numques * 100 << "%";
			ques = 0;	   // reset variables￺冘飙縋一乍伍
			numcorrect = 0;
			cout << endl;
			continue;
		}
		ques++;
	}
	return 0;
}

void pointer_array()
{
	int line1[] = { 1,0,0 };	//声明数组，矩阵的第一行
	int line2[] = { 0,1,0 };	//声明数组，矩阵的第二行
	int line3[] = { 0,0,1 };	//声明数组，矩阵的第三行

	int *p_line[3];	//声明整型指针数组
	p_line[0] = line1;	//初始化指针数组元素
	p_line[1] = line2;
	p_line[2] = line3;

	cout << "Matrix test:" << endl;	//输出单位矩阵
	for (int i = 0; i < 3; i++)	//对指针数组元素循环
	{
		for (int j = 0; j < 3; j++)	//对矩阵每一行循环
		{
			cout << p_line[i][j] << " ";
		}
		cout << endl;
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

	pointer_array();
	char_array();
	return 0;
}
