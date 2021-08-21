// ***************************************************************
// device.cpp
// 演示多重继承中的相关问题
// ***************************************************************
#include <iostream>
using namespace std;
class Device1 {
public:
	Device1() 
	{
		cout << "Initializing device 1 by default constructor in Device1..." << endl;
		volume = 5;
		powerOn = false;
	}
	Device1(int vol, bool onOrOff) 
	{
		cout << "Initializing device 1 by constructor with parameters in Device1..."
              	<< endl;
		volume = vol;
		powerOn = onOrOff;
	}
	void showPower()
	{
		cout << "The status of the power is :" ; 
		switch (powerOn) {
			case true: 
				cout << "Power on. \n"; 
				break;
			case false: 
				cout << "power off. \n"; 
				break;  
		}
	}
	void showVol() 
	{ 
		cout << "Volume is " << volume << endl;
	}
protected:
	int volume;    	// 音量
	bool powerOn;  	// 开关状态
};
class Device2 {
public:
	Device2() 
	{
		cout << "Initializing device 2 by default constructor in Device2..." << endl;
		talkTime = 10; 
		standbyTime = 300; 
		power = 100; 
	}
	Device2(int newTalkTime, int newStandbyTime, float powerCent) 
	{
		cout << "Initializing device 2 by constructor with parameters in Device2..."
               	<< endl;
		talkTime = newTalkTime; 
		standbyTime = newStandbyTime; 
		power = powerCent; 
	}
	void showProperty()
	{   
		cout << "The property of the device : "<< endl;
		cout << "talk time: " << talkTime << " hours" << endl;
		cout << "standbyTime: " << standbyTime << " hours" << endl;
	}
	void showPower () 
	{
		cout <<" Power: " << power << endl;
	}
protected:
	int  talkTime; 	//可通话时间（小时）
	int  standbyTime; 	//可待机时间（小时）
	float power;		//剩余电量百分比
};
class DeviceNew: public Device1, public Device2 {
public:
	DeviceNew()
	{
		cout << "Initializing device new by default constructor in DeviceNew..." << endl;
		weight = 0.56;
	} 
	DeviceNew(float newWeight, int vol, bool onOrOff, int newTalkTime, int newStandby-
        		Time, float powerCent): Device2(newTalkTime, newStandbyTime, powerCent),
 		Device1(vol, onOrOff)
	{
		cout << "Initializing device new by constructor with parameters in DeviceNew ..."
 			<< endl;
		weight = newWeight;
	} 
	float getWeight()
	{
		return weight;
	}
private:
	float weight; 	// 重量（克）
};
int main()
{   
	// 声明一个派生类对象
	DeviceNew  device;
	// getWeight()函数是DEVICE_NEW类自身定义的
 	cout << "The weight of the device : " << device.getWeight() << endl; 
	// showVol()函数是从DEVICE1类继承来的
	device.showVol();
	// showProperty()函数是从DEVICE2类继承来的
	device.showProperty();
	return 0;
}
