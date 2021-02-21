#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//抽象的水果类
class Fruit
{
public:
	virtual void getName() = 0;
};

class Apple :public Fruit
{
public:
	virtual void getName() {
		cout << "我是苹果" << endl;
	}
 };

class Banana :public Fruit
{
public:
	virtual void getName() {
		cout << "我是香蕉" << endl;
	}
};

//添加一个新产品 鸭梨
class Pear :public Fruit
{
public:
	virtual void getName() {
		cout << "我是鸭梨" << endl;
	}
};

//工厂
class Factory {
public:
	//水果生产器
	Fruit * createFruit(string kind) {
		Fruit *fruit = NULL;

		if (kind == "apple") {
			fruit =  new Apple;
		}
		else if(kind == "banana"){
			fruit =  new Banana;
		}
		//添加一个鸭梨   修改了工厂的方法， 违背了开闭原则
		else if (kind == "pear") {
			fruit = new Pear;
		}
		return fruit;
	}
};

int main(void)
{
	//人们是跟工厂打交道
	Factory *factory = new Factory; //创建一个工厂
	//给我来一个苹果
	Fruit *apple = factory->createFruit("apple");

	apple->getName();


	Fruit *banana = factory->createFruit("banana");
	banana->getName();

	Fruit *pear = factory->createFruit("pear");

	delete apple;
	delete banana;
	delete factory;

	
	return 0;
}