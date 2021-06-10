程序清单14-2

// ***************************************************************
// accessElementByIterator.cpp
// 功能： 演示通过迭代器访问顺序容器中的元素
// ***************************************************************
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec(10, 2); 				// 创建含10个值为2的元素的vector容器
	vector<int>::iterator iter;			// 声明迭代器对象
	vector<int>::reverse_iterator riter;	// 声明逆向迭代器对象


	iter = ivec.begin();	// 获取指向第一个元素的迭代器
	*iter += 10;			// 将第一个元素的值加10

	riter = ivec.rend();	// riter指向第一个元素的前一位置
	*(riter-1) += 10;		// 将第一个元素的值加10

	iter = ivec.end();	// iter指向最后一个元素的下一位置
	*(iter-1) = 100;		// 将最后一个元素的值改为100

	riter = ivec.rbegin();	// riter指向最后一个元素
	*riter -= 20;			// 将最后一个元素的值减20

	// 输出容器中的所有元素
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}
