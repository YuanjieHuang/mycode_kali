// ***************************************************************
// containerCompare.cpp
// 功能： 演示顺序容器的比较操作
// ***************************************************************
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	int iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> ilist1(iarr, iarr+10);
	list<int> ilist2(iarr, iarr+5);
	list<int> ilist3(ilist2);
	list<int> ilist4(ilist2);
	ilist4.push_back(12);
	ilist4.push_back(7);
	list<int>::iterator iter, ibegin, iend;
	string name;
	// 输出4个list对象
	for (int i = 1; i < 5; i++) {
		// 设置list对象的名字和迭代器范围[ibegin, iend)
		switch (i) {
			case 1:
				name = "list1";
				ibegin = ilist1.begin();
				iend = ilist1.end();
				break;
			case 2:
				name = "list2";
				ibegin = ilist2.begin();
				iend = ilist2.end();
				break;
			case 3:
				name = "list3";
				ibegin = ilist3.begin();
				iend = ilist3.end();
				break;
			case 4:
				name = "list4";
				ibegin = ilist4.begin();
				iend = ilist4.end();
				break;
		}
		// 输出list对象
		cout << name << ": ";
		for (iter = ibegin; iter != iend; iter++)
			cout << *iter << ' ';
		cout << endl;
	}
	cout << endl;
	// 比较list对象并输出结果
	cout << "ilist2 == ilist3 : ";
	if (ilist2 == ilist3)
		 cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "ilist1 < ilist2 : ";
	if (ilist1 < ilist2)
		 cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "ilist3 > ilist4 : ";
	if (ilist3 > ilist4)
		 cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "ilist1 < ilist4 : ";
	if (ilist1 < ilist4)
		 cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "ilist2 != ilist4 : ";
	if (ilist2 != ilist4)
		 cout << "true" << endl;
	else
		cout << "false" << endl;
}
