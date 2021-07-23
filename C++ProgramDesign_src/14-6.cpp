// ***************************************************************
// phoneNumberBook.cpp
// 功能： 利用map容器类实现电话号码本
// 电话号码本中的条目按姓名排列（假设没有重名的条目）
// 程序支持用户创建并维护一个电话号码本：
// 可以往电话号码本中添加条目、可以删除指定条目、
// 可以修改指定条目中的电话号码、
// 可以指定姓名查询电话号码、可以显示电话号码本的内容。
// ***************************************************************
#include <iostream>
#include <map>
#include <string>
#include <utility>		// 使用其中的make_pair()
using namespace std;
void printMenu();
int main()
{	
	map<string, string> phoneNumBook;	// 电话号码本
	string name;						// 姓名
	string endName;					// 要删除的最后一个姓名
	string phoneNumber;				// 电话号码
	// 用于访问容器中元素的迭代器
	map<string, string>::iterator iter, beginIter, endIter;	
	int choice = 1;
	while (choice != 0) {
		// 显示菜单
		printMenu();
		// 获取用户选择
		cout << "Enter your choice:";
		cin >> choice;
		// 根据用户选择分别进行处理
		switch (choice) {
			case 1:	// 插入条目
				cout << "Enter the name you want to insert: ";
				cin >> name;
				cout << "Enter the phone number(s) : ";
				cin >> phoneNumber;
				phoneNumBook.insert(make_pair(name, phoneNumber));
				break;
			case 2:	// 删除一个条目
				cout << "Enter the name you want to delete: ";
				cin >> name;
				phoneNumBook.erase(name);
				break;
			case 3:	// 根据名字查找号码
				cout << "Enter the name you want to search: ";
				cin >> name;
				iter = phoneNumBook.find(name);
				if (iter == phoneNumBook.end()) 
					cout << "No such name in the phone number book." << endl;
				else
					cout << "The phone number of " << name << " is " 
						 << (*iter).second << endl; 
				break;
			case 4:	// 删除多个条目
				cout << "Enter the first name you want to delete: ";
				cin >> name;
				cout << "Enter the last name you want to delete: ";
				cin >> endName;
				// 因为键为const类型，所以需要强制类型转换
				beginIter = phoneNumBook.find(
				static_cast<const string>(name));
				endIter = phoneNumBook.find(
				static_cast<const string>(endName));
				// erase操作不删除第二个迭代器所指向的元素，所以先将迭代器向后移动一个元素
				endIter++;	
				phoneNumBook.erase(beginIter, endIter);
				break;
			case 5:			// 修改指定条目中的电话号码
				cout << "Enter the item you want to modify: ";
				cin >> name;
				if (phoneNumBook.count(static_cast<const string>(name)) == 0)
				{
					cout << "No such name in the phone number book!" << endl;
				break;
				}
				cout << "Enter the new phone number:";
				cin >> phoneNumber;
				phoneNumBook[static_cast<const string>(name)] = phoneNumber;
				break;
			case 6:			// 列出电话号码本的内容
				cout << "content of the phone number book: " << endl;
				for (iter = phoneNumBook.begin(); 
					    iter != phoneNumBook.end(); iter++)
					    cout << (*iter).first << "\t" 
						     << (*iter).second << endl;
				break;
			case 0:			// 退出
				break;
		}
	}
	return 0;
}
void printMenu()
// 功能：输出选择菜单
{
	cout << endl;
	cout << "*********************************************" << endl;
	cout << "  1--insert		2--delete a item" << endl;
	cout << "  3--search		4--delete some items" << endl;
	cout << "  5--modify		6--display" << endl;
	cout << "  0--quit" << endl;
	cout << "*********************************************" << endl;
}
