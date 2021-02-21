#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;


class Car
{
public:
	void run() {
		cout << "Car 启动了" << endl;
	}
};

//如果说 zhang3 类 有一个成员方法，将Car类当做一个形参来传递，并且zhang3没有car成员。
//就说 zhang3类依赖于Car类  张3 -----> Car
class Zhang3
{
public:
	void goWork(Car * car) {
		car->run();
	}

	Car *fix() {

	}
};


//li4类 在gowork方法中 用到了另外一个Car的方法，并且LI4类还拥有Car的成员， 就说li4类关联Car类
class Li4
{
public:
	void goWork() {
		car.run();
	}
private:
	Car car;
};
int main(void)
{
	
	
	return 0;
}