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

SavingsAccount::SavingsAccount(int date, int id, double rate)
{
	accumulation = accumulate(date);
	lastDate = date;
	double amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	balance += amount;
}
int main()
{

    std::cout << "Hello World!\n"; 
}
