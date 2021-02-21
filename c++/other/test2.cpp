// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount {//储蓄账户类
private:
	int id;		//账号
	double balance;		//余额
	double rate;	//存款得年利率
	int lastDate;	//上次变更余额得时期
	double accumulation;	//余额按日累加之和

	//记录一笔账，data为日期，amount为金额，desc为说明
	void reecord(int date, double amount);
	//获得到指定日期为止得存款金额按日累计值
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//构造函数
	SavingsAccount(int date, int id, double rate);
	int getId() { return id; }
	double getBalance() { return balance; }
	double getRate() { return rate; }

	//存入现金
	void deposit(int date, double amount);
		//取出现金
	void withdraw(int date, double amount);
	//结算利息，每年1月1日调用一次该函数
	void settle(int date);
	//显示账号信息
	void show();
};

//SavingsAccount类相关成员函数得实现
SavingsAccount::SavingsAccount(int date, int id, double rate)
	:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << "\t#" << id << "is create" << endl;
}

void SavingsAccount::SavingsAccount(int date, int id, double rate)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	balance + = amount;
}
int main()
{

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
