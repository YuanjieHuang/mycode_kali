程序清单14-1
// ***************************************************************
// elementAccessDemo.cpp
// 功能： 演示在顺序容器中访问元素的操作
// ***************************************************************
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> ivec(ia, ia+10);// ivec包含10个元素，值分别为0~9

	// 将第一个元素修改为100
	ivec.front() = 100;
	// 输出第一个元素的值
	cout << "the first element: " << ivec[0] << endl;

	// 将第二、第三个元素修改为102、103
	ivec[1] = 102;
	ivec.at(2) = 103;
	// 输出第二、第三个元素的值
	cout << "the second element: " << ivec.at(1) << endl;
	cout << "the third element: " << ivec[2] << endl;

	// 将最后一个元素修改为999
	ivec.back() = 999;
	// 输出最后一个元素的值
	cout << "the last element: " << ivec[9] << endl;

	return 0;
}
