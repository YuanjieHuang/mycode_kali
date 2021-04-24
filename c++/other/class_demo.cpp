
#include <iostream>
using namespace std;

enum CPU_Rank { P1 = 1,P2,P3,P4,P5,P6,P7};	//声明枚举类CPU_Rank，从P1-P7依次上升

class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	double voltage;
public:
	CPU(CPU_Rank r, int f, double v) {		//构造函数
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU！" << endl;
	}
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

int main()
{
    //std::cout << "Hello World!\n"; 
	CPU a(P6,300,2.8);		//声明一个CPU的对象
	a.Run();
	a.Stop();
	return 0;
}


