// ***************************************************************
// memberOpOverloading.cpp
// 用成员函数实现操作符重载
// ***************************************************************
#include <iostream>
using namespace std;
class Pos { 
public:
	Pos( float newPos_x=0, float newPos_y=0) 
	{  
		pos_x=newPos_x;
		pos_y=newPos_y; 
	}
	Pos operator+ (Pos &); // 重载 + 操作符的成员函数
	void showPos() 
	{ 
		cout<<"x="<<pos_x<<'\t'<<"y="<<pos_y<<'\t' <<endl;
	}
private:  
	float pos_x;
	float pos_y;
};
Pos Pos::operator+ (Pos & anoPos)
{  
	Pos temp;
	temp.pos_x =pos_x + anoPos.pos_x;
	temp.pos_y = pos_y + anoPos.pos_y;
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
