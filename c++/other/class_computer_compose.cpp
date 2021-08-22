/*
类的基本类型可以是基本数据类型，也可以是自定义类型（含有类的对象）

例子：
部件组装->构造与析构顺序

声明CPU类、RAM类、CDROM类和Computer类
要求：
1.其中声明私有数据成员cpu、ram、carom，声明公有成员函数run、stop，可在其中输出提示信息
2.在main（）函数中声明一个Computer类的对象，调用其成员函数
*/
#include <iostream>
using namespace std;

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };	//声明枚举类CPU_Rank，从P1-P7依次上升

class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU(CPU_Rank r, int f, float v) {		//构造函数
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU！" << endl;
	}

	/*CPU(CPU  &c)
	{
		rank = c.rank;
		frequency = c.frequency;
		voltage = c.voltage;

		cout << "拷贝构造了一个CPU！" << endl;
	}*/

	~CPU() {								//析构函数
		cout << "析构了一个CPU！" << endl;
	}

	CPU_Rank GetRank()const { return rank; }			//外部接口函数
	int GetFrequency()const { return frequency; }
	float GetVoltage()const { voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU开始运行！" << endl; }
	void Stop() { cout << "CPU停止运行！" << endl; }
};

enum RAM_Type{DDR2 = 2,DDR3,DDR4};
class RAM {							//声明RAM类
private:
	enum RAM_Type type;
	unsigned int frequency;		//MHz
	unsigned int size;			//GB

public:
	RAM(RAM_Type t, unsigned int f, unsigned int s)		//构造函数
	{
		type = t;
		frequency = f;
		size = s;
		cout << "构造了一个RAM！" << endl;
	}
	~RAM() { cout << "析构了一个RAM！" << endl; }

	RAM_Type GetType()const { return type; }			//外部接口函数(设置三个私有成员)
	int GetFrequency()const { return frequency; }
	float Getsize()const { size; }

	void SetType(RAM_Type t) { type = t; }				//获取三个私有成员的值
	void SetFrequency(int f) { frequency = f; }
	void SetSize(float s) { size = s; }

	void Run() { cout << "RAM开始运行！" << endl; }
	void Stop() { cout << "RAM停止运行！" << endl; }
};

enum CDROM_Interface {SATA,USB};
enum CDROM_Install_Type {xternal,built_in};
class CD_ROM{							//声明类
private:
	enum CDROM_Interface interface_type;
	unsigned int cache_size;		//MB
	CDROM_Install_Type install_type;			

public:
	CD_ROM(CDROM_Interface i, unsigned int s,CDROM_Install_Type it)		//构造函数
	{
		interface_type = i;
		cache_size = s;
		install_type = it;
		cout << "构造了一个RAM！" << endl;
	}
	~CD_ROM() { cout << "析构了一个CD_ROM！" << endl; }

	CDROM_Interface GetInterfaceType()const { return interface_type; }			//外部接口函数(设置三个私有成员)
	unsigned int GetSize()const { return cache_size; }
	CDROM_Install_Type GetInstallType()const { return install_type; }

	void SetInterfaceType(CDROM_Interface i) { interface_type = i; }				//获取三个私有成员的值
	void SetSize(unsigned int s) { cache_size = s; }
	void SetInstallType(CDROM_Install_Type it) { install_type = it; }

	void Run() { cout << "CD_ROM开始运行！" << endl; }
	void Stop() { cout << "CD_ROM停止运行！" << endl; }
};

class COMPUTER
{
private:
	CPU my_cpu;
	RAM my_ram;
	CD_ROM my_cdrom;
	unsigned int storage_size;		//GB
	unsigned int bandwidth;			//MB,带宽
public:
	COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b);
	~COMPUTER(){cout << "析构了一个COMPUTER！" << endl; }

	void Run()
	{
		my_cpu.Run();
		my_ram.Run();
		my_cdrom.Run();
		cout << "COMPUTER开始运行！" << endl;
	}

	void Stop()
	{
		my_cpu.Stop();
		my_ram.Stop();
		my_cdrom.Stop();
		cout << "COMPUTER停止运行！" << endl;
	}
};

COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b):my_cpu(c), my_ram(r), my_cdrom(cd) 
{
	storage_size = s;
	bandwidth = b;

	cout << "构造了一个COMPUTER！" << endl;
}

int main()
{
	CPU a(P6, 300, 2.8);		//声明一个CPU的对象并初始化
	a.Run();					//让已经声明的a运行Run（）公有成员函数
	a.Stop();
	cout << "***********\n" ;

	RAM b(DDR3, 1600, 8);
	b.Run();
	b.Stop();
	cout << "***********\n" ;

	CD_ROM c(SATA,2,built_in);
	b.Run();
	b.Stop();
	cout << "***********\n";

	COMPUTER my_computer(a, b, c, 128, 10);
	cout << "**********\n";
	my_computer.Run();
	my_computer.Stop();
	cout << "********\n";		//后创建先析构

	return 0;
}
/*
output:
构造了一个CPU！
CPU开始运行！
CPU停止运行！
***********
构造了一个RAM！
RAM开始运行！
RAM停止运行！
***********
构造了一个RAM！
RAM开始运行！
RAM停止运行！
***********
构造了一个COMPUTER！
析构了一个CPU！-------->why?
析构了一个RAM！
析构了一个CD_ROM！
**********
CPU开始运行！
RAM开始运行！
CD_ROM开始运行！
COMPUTER开始运行！
CPU停止运行！
RAM停止运行！
CD_ROM停止运行！
COMPUTER停止运行！
********
析构了一个COMPUTER！
析构了一个CD_ROM！
析构了一个RAM！
析构了一个CPU！
析构了一个CD_ROM！
析构了一个RAM！
析构了一个CPU！
*/



