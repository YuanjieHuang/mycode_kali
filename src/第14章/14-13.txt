　　//文件名：14-13.cpp
　　//图书馆系统的主函数
　　#include "book.h"
　　void initialize();	//系统初始化
　　void addBook();		//添加新书
　　void borrowBook();	//借书
　　void returnBook();	//还书
　　void displayBook();	//显示所有的书目信息
　　
　　int main()
　　{   int selector;
　　
　　    while (true) {
　　        cout << "0 -- 退出\n";
　　        cout << "1 -- 初始化文件\n";
　　        cout << "2 -- 添加书\n";
　　        cout << "3 -- 借书\n";
　　        cout << "4 -- 还书\n";
　　        cout << "5 -- 显示所有书目信息\n";
　　        cout << "请选择（0-5）："; cin >> selector;
　　        if (selector == 0) break;
　　        switch (selector)	{
　　            case 1: initialize(); break;
　　            case 2: addBook(); break;
　　            case 3: borrowBook();break;
　　            case 4: returnBook(); break;
　　            case 5: displayBook();break;
　　        }
　　    }
　　    return 0;
　　}
　　
