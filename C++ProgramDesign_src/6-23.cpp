// ********************************************************
// mainPara.cpp
// 功能：介绍main函数参数的使用
// ********************************************************
#include <iostream>
#include <cstring> // 使用strcmp
using namespace std;
void helpingMessage();
void om();
void im();
void of();
void inf();
int main( int argc, char *argv[])
{
    if ( argc != 2 ) 
		helpingMessage();
    else if( !strcmp( argv[1], "-OM" ) )
		om();
    else if( !strcmp( argv[1], "-OF" ) )
		of();
    else if( !strcmp( argv[1], "-IM" ) )
		im();
    else if( !strcmp( argv[1], "-IF" ) )
		inf();
    else
		helpingMessage();
    return 0;
}
void helpingMessage()
{
    cout << endl;
    cout << "这个命令要带有参数:" << endl;
    cout << "MainPara -OM  输出男生数据" << endl;
    cout << "MainPara -OF  输出女生数据" << endl;
    cout << "MainPara -IM  输入男生数据" << endl;
    cout << "MainPara -IF  输入女生数据" << endl;
}
void om()
{
    cout << endl << "调用输出男生数据函数" << endl;
}
void im()
{
    cout << endl << "调用输入男生数据函数" << endl;
}
void of()
{
    cout << endl << "调用输出女生数据函数" << endl;
}
void inf()
{
    cout << endl << "调用输入男生数据函数" << endl;
}
