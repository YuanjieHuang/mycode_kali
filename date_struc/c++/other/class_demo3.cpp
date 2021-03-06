#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*class Clock{
public:void setTime(int newH,int newM,int newS);
		void showTime();
private:int hour,minute,second;
};


类的定义：
class 类名称
{
public：
	公有成员（外部接口）   //公有数据和函数 
private：
	私有成员                //只允许类内访问 ，最开头声明可以省略关键字 
protected：
	保护成员	 			// 
}；
类内的初始化：
class Clock{
public:void setTime(int newH,int newM,int newS);
		void showTime();
private:
	int hour = 0,minute = 0,second = 0;    //类内初始化 
}; 

内联函数：
构造函数：
	1.Clock myClock(0,0,0)
默认构造函数：
	Clock(); 
	即：
	Clock::Clock():hour(0),minute(0),second(0){};
	主函数中：
	int main(){
		Clock c1(8,9,0);  //调用有参数的构造函数
		Clock c2;      //调用没有参数的构造函数(默认构造函数)
		..... 
}
隐含生成的构造函数：
class Clock{
public:
	Clock()=default;    //指示编译器提供默认构造函数
	Clock(int newH,int newM, int newS);      //构造函数 
private:
	int hour = 0,minute = 0,second = 0;    //类内初始化 
};  

//构造函数：
class Clock{
public:
	Clock(int newH,int newM, int newS);      //构造函数 
	void setTime(int newH,int newM,int newS);
	void showTime();
private:
	int hour,minute,second;    //类内初始化 
};  
 构造函数的实现：
 Clock::Clock(int newH,int newM,int newS):
 hour(newH),minute(newM),second(newS){
}   //newH赋值给hour，后面类似（效率高一点）


委托构造函数
//Clock(int newH,int newM,int newS):hour(newH),minute(newM),second(newS){}
Clock():Clock(0,0,0){}

复制构造函数:
//class 类名{
public:
类名(形参)；   //构造函数
类名（const 类名 &对象名）；    //复制构造函数  const保证不改变实参的值，只读不写 
//... 
} ;
类名::类(const 类名 &对象名）   //复制构造函数的实现
{函数体} 
复制函数被调用的三种情况
1.初始化
2.如果函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象，发生复制构造
3.如果函数的返回值时类的对象，函数执行完成返回主函数时，将使用return语句中的类的对象初始化一个临时无名对象，传递给主调函数，发生复制函数
指示编译器不生成默认复制构造函数：：Point（const Point&p)=delete;
class Point{//类的定义
public:
	Point(int xx=0,int yy=0){x=xx,y=yy;}  //构造函数，内联
	Point(const Point&p)=delete;   //指示编译器不生成默认的复制构造函数
private:
	int x,y;   //私有数据
	}； 
 
 

*/ 
class Clock{
	//时钟类的定义
	public:    //外部接口，公有成员函数
		Clock(int newH=0,int newM=0,int newS=0);  //构造函数 
		Clock();   //默认构造函数
		void setTime(int newH=0,int newM=0,int newS=0);
		void showTime();
	private:   //私有数据成员
	 	int hour,minute,second; 
	 };

//时钟类成员函数的具体实现
Clock::Clock():hour(0),minute(0),second(0) {
}    //默认构造函数 

Clock::Clock(int newH,int newM,int newS):
	hour(newH),minute(newM),second(newS){
} //newH赋值给hour，后面类似（效率高一点） 

void Clock::setTime(int newH,int newM,int newS) {
	hour=newH;
	minute = newM;
	second = newS;
}

inline void Clock::showTime() {
	cout<<hour<<":"<<minute<<":"<<second<<endl; 
} 

int main(int argc, char** argv) {
	Clock c(0,0,0);  //自动调用构造函数
	c.showTime(); 
	return 0;
}    //
