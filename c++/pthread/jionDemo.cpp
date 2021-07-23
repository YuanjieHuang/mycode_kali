#include<iostream>
#include<thread>
using namespace std;

// 子线程函数
void function_1()
{
    for(int i=10;i>0;i--) // 循环10次输出
        cout << "=============Hello=============" << endl;
}

int main()
{
    thread t1(function_1);//线程开始

    // t1.join();//方式1：结合（等待其完成）
    t1.detach();//方式2：分离（使其自行运行）（cout未来得及输出完毕，主线程已结束）
    
    cout << "~~~~~~~~~~~World~~~~~~~~~~~" << endl;
    
    if (t1.joinable())
    {
        t1.join();
    }
    
    return 0;
}