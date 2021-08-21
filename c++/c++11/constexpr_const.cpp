#include <iostream>
#include <array>
using namespace std;
void dis_1(const int x){
    //错误，x是只读的变量
    array <int,x> myarr{1,2,3,4,5};
    cout << myarr[1] << endl;
}
void dis_2(){
    const int x = 5;
    array <int,x> myarr{1,2,3,4,5};
    cout << myarr[1] << endl;
}
int main()
{
   dis_1(5);
   dis_2();
}
/*
dis_1() 函数中的“const int x”只是想强调 x 是一个只读的变量，其本质仍为变量，无法用来初始化 array 容器；
而 dis_2() 函数中的“const int x”，表明 x 是一个只读变量的同时，x 还是一个值为 5 的常量，所以可以用来初始化 array 容器。
*/
constexpr int sqr1(int arg){
    return arg*arg;
}
const int sqr2(int arg){
    return arg*arg;
}
int main()
{
    array<int,sqr1(10)> mylist1;//可以，因为sqr1时constexpr函数
    array<int,sqr2(10)> mylist1;//不可以，因为sqr2不是constexpr函数
    return 0;
}