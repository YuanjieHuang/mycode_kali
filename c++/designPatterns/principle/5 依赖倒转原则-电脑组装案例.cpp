#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//抽象层--------
class CPU
{
public:
	virtual void caculate() = 0;
};

class Card
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

//架构类
class Computer
{
public:
	Computer(CPU *cpu, Card*card, Memory * mem)
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}

	void work() {
		cpu->caculate();
		card->display();
		mem->storage();
	}
private:
	CPU *cpu;
	Card*card;
	Memory *mem;
};


//  实现层 
class IntelCPU :public CPU{
public:
	virtual void caculate()  {
		cout << "Intelcpu 工作了" << endl;
	}
};

class NvidiaCard :public Card
{
public:
	virtual void display() {
		cout << "N卡 显示了" << endl;
	}
};

class XSMem :public Memory {
public:
	virtual void storage()  {
		cout << "西部数据的内存工作了" << endl;
	}
};


//高层业务
int main(void)
{
	CPU *cpu = new IntelCPU;
	Card *card = new NvidiaCard;
	Memory *mem = new XSMem;
	Computer *com = new Computer(cpu, card, mem);


	com->work();

	delete cpu;
	delete card;
	delete mem;
	delete com;
	
	return 0;
}