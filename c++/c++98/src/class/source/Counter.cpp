#include <iostream>
using namespace std;

class Counter {
    int value; //计数器的值 
    int alarm; //报警值
public:
    Counter(int a) {value = 0; alarm = a;}
    Counter & operator++();  //前缀的++重载
    Counter operator++(int); //后缀的++重载
    void print() {cout << value << endl; }
};

Counter & Counter::operator++()
{   if (value == alarm) cout << "已超过报警值\n";
        else { ++value;
                if (value == alarm) cout << "已到达报警值\n";
        }
    return *this;
}

Counter Counter::operator++(int x)
{   Counter tmp = *this; 			//保存对象修改前的状态
    if (value == alarm) cout << "已超过报警值\n";
        else { ++value;
                if (value == alarm) cout << "已到达报警值\n";
        }
    return tmp;				 //返回修改前的状态
}

int main()
{   
    Counter cnt(3); 		//定义一个Counter类的对象，报警值为3

    cnt.print(); 			//显示对象的当前值，此时输出为0
    ++cnt;
    cnt.print(); 			//此时输出为1
    (++cnt).print(); 		//调用前缀的++，输出2
    (cnt++).print(); 		//调用后缀的++，当前对象的value已经加1，报警，但输出的是2
    cnt.print(); 			//输出值为3
    return 0;
}

