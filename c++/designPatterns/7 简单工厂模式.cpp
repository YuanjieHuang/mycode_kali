#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

class Fruit
{
public:
	Fruit(string kind)
	{
		this->kind = kind;
		if (kind == "apple") {
			//代表苹果
			//苹果的初始化方式
		}
		else if (kind == "banana") {
			//代表香蕉
			//香蕉的初始化方式
		}
	}

	void getName() {
		if (this->kind == "apple") {
			cout << "我是苹果" << endl;
		}
		else if (this->kind == "banana"){
			cout << "我是香蕉" << endl;
		}
	}
private:
	string kind;//代表水果的种类
};

int main(void)
{
	//创建一个苹果
	Fruit *apple = new Fruit("apple");
	apple->getName();
	delete apple;

	//main函数跟Fruit类的构造函数耦合度高， 随着水果种类的增加 构造函数越来越复杂
	
	return 0;
}