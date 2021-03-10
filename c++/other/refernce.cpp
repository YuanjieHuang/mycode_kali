#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int &ri = i;    定义int引用ri，并初始化为变量i的引用 
void swap(int &a,int &b){
	int t = a;
	a=b;
	b=t;
}
int main(int argc, char** argv) {
	int x=5,y=10;
	cout <<"x="<<x<<"y="<<y<<endl;
	swap(x,y);
	cout <<"x="<<x<<"y="<<y<<endl;
	return 0;
}
