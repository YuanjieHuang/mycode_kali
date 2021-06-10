程序清单8-2 
// ***************************************************************
// carSportCar.cpp
// 演示了小汽车和跑车之间的继承关系
// ***************************************************************

#include <string>
#include <iostream>

using namespace std;

class Car {
public:
	Car(int Weight,int Speed) 	// 构造函数
	{   
		weight = Weight;
		speed = Speed;
	}

	void setWeight(int Weight) 	// 设置重量
	{
		weight = Weight;
	}

	void setSpeed(int Speed) 	// 设置速度
	{
		speed = Speed;
	}

	int getSpeed() 	// 获取速度
	{
		return speed;
	}

	int getWeight() 	// 获取重量
	{
		return weight;
	}

private:
	int weight;
	int speed;
};

class SportCar: public Car {
public:
	SportCar(int Weight,int Speed,string Color):Car(Weight,Speed)
	{
		color = Color;
	}

	void setColor(string Color)
	{
		color = Color;
	}

	string getColor()
	{
		return color;
	}

private:
	string color; 		// 跑车的颜色
};

int main()
{
	Car car(100,100);
	SportCar sportCar(100,200,"black");                      
	cout << "car‘s weight is " << car.getWeight() << endl;;
	cout << "car‘s speed is " << car.getSpeed() << endl;
	cout << "sportcar‘s weight is " << sportCar.getWeight() << endl;
	cout << "sportcar‘s speed is " << sportCar.getSpeed() << endl;
	cout << "sportcar‘s color is " << sportCar.getColor()<< endl;

	return 0;
}
