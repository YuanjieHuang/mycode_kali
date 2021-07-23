// ***************************************************************
// friendOpOverloading.cpp
// 使用友元实现操作符的重载
// ***************************************************************
#include <iostream>
using namespace std;
class Pos {
public:
	Pos( float newPos_x=0, float newPos_y=0) 
	{  
		pos_x = newPos_x;
		pos_y = newPos_y;
	}
	void showPos() 
	{ 
		cout<<"x="<<pos_x<<'\t'<<"y="<<pos_y<<'\t' <<endl;
	}
	friend Pos operator+ (Pos&, Pos&); // 重载 + 操作符的友元函数
private:  
	float pos_x;
	float pos_y;
};
Pos operator+ (Pos& pos1, Pos& pos2)
// 将两个Pos对象点相加
// 前置条件：pos1, pos2已赋值
// 后置条件：返回值为一个Pos对象,其x和y坐标分别为pos1和pos2的x和y坐标的和
{  
	Pos temp;
	temp.pos_x = pos1.pos_x + pos2.pos_x;
	temp.pos_y = pos1.pos_y + pos2.pos_y;
	return temp;
}
void main(void)
{  
	Pos pos1(25,50), pos2(1,2);
	Pos pos3;
	cout << "Pos 1:\n";
     pos1.showPos();
     cout <<"Pos 2:\n";
     pos2.showPos();
     cout <<"Pos 1 + Pos 2:\n";
     pos3 = pos1 + pos2;
     pos3.showPos();
}
