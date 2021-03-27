#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//抽象的手机接口
class Phone
{
public:
	virtual void show() = 0;
};

//实现接口
class iPhone :public Phone
{
public:
	virtual void show() {
		cout << "秀出了iphone" << endl;
	}
};

class Mi :public Phone
{
	virtual void show() {
		cout << "秀出了小米手机" << endl;
	}
};

//写一个抽象的装饰器
class Decorator :public Phone
{
public:
	Decorator(Phone *phone) {
		this->phone = phone;
	}

	virtual void show() = 0;
protected:
	Phone * phone; //拥有一个 所有手机的父类指针
};

//具体的手机贴膜装饰器
class MoDecorator :public Decorator
{
public:
	MoDecorator(Phone *phone) : Decorator(phone) {}
	virtual void show() {
		this->phone->show();  //保持原有的show

		this->mo(); //额外添加一个 mo的方法
	}

	//膜装饰器，可以修饰添加的方法
	void mo() {
		cout << "手机有了贴膜" << endl;
	}
};

//皮套的装饰器类
class TaoDecorator :public Decorator
{
public:
	TaoDecorator(Phone *phone) : Decorator(phone) {}
	virtual void show() {
		this->phone->show();
		tao();
	}

	void tao() {
		cout << "手机有了皮套" << endl;
	}
};



int main(void)
{
	Phone *phone = new iPhone;
	phone->show();
	cout << " -----  " << endl;
	Phone * moPhone = new MoDecorator(phone);
	moPhone->show();
	cout << " -----  " << endl;
	Phone * taoPhone = new TaoDecorator(phone);
	taoPhone->show(); 

	cout << " ------  " << endl;
	Phone *moTaoPhone = new TaoDecorator(moPhone);
	moTaoPhone->show(); //moPhone.show() + tao() ==  phone.show() + mo() + tao();

	
	return 0;
}