// ***************************************************************
// demoFriend.cpp
// 友元及其使用的演示
// ***************************************************************
#include <iostream>    
#include <string>
using namespace std;  
class House {    
public:    
    House (string name,  string address)    
    {    
        House::name =  name;    
        House::address = address;     
    }  
    friend void showHouse(House &newHouse); 	// 友元函数的声明  
private:    
    string name;  
    string address;  
};  
// 友元函数的定义
void showHouse(House &newHouse) 
// 输出一所房子的信息
// 前置条件：newHouse已赋值
// 后置条件：输出房子信息
{  
	cout << newHouse.name << endl; 			// 可以访问类House的私有成员name
	cout << newHouse.address << endl; 		// 可以访问类House的私有成员address
}  
void main()    
{  
    House  clientHouse ("王一一","某市某街道某楼");  
    showHouse(clientHouse);  
}
