#include <iostream>
using namespace std;
class A
{
public:
	virtual void func() {
		cout << "A" << endl;
	}
	int a;
};
class B :public A
{
public:
	virtual void func() {
		cout << "B" << endl;
	}
	int b;
};
//动物的抽象类
class Animal
{
public:
	virtual void cry() = 0;// 纯虚函数
	virtual void doHome() = 0;// 纯虚函数
};
class Dog :public Animal {
public:
	virtual void cry()  {
		cout << "汪汪~~" << endl;
	}
	void doHome() {
		cout << "看家" << endl;
	}
};
class Cat :public Animal {
public:
	virtual void cry() {
		cout << "喵喵~~" << endl;
	}
	void doHome() {
		cout << "抓老鼠" << endl;
	}
};
int main(void)
{
	Animal *animal = NULL;
	animal = new Dog;
	animal->cry();
	Dog *dog = new Dog;
	cout << " ----- " << endl;
	dog =  dynamic_cast<Dog*> (animal);
	if (dog != NULL) {
		cout << "转换成功" << endl;
		dog->cry();
		dog->doHome();
	}
	else {
		cout << "转换失败" << endl;
	}
	//dynamic _cast 是将父类转换成子类。让老子变成儿子。
	//让子类指针执行父类的对象。
	Cat *cat = dynamic_cast<Cat*>(animal);
	//准备试图让一只狗变成一只猫
	if (cat != NULL) {
		cout << "转换成功" << endl;
		cat->cry();
		cat->doHome();
	}
	else {
		cout << "转换失败" << endl;
	}
	A *ap = new A;
	B *bp = dynamic_cast<B*>(ap);
	if (bp != NULL) {
		bp->func();
	}
	return 0;
}