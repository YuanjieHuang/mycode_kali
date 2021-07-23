#include<iostream>
#include<thread>
#include<opencv2/opencv.hpp>

// 子线程函数（假定该函数比较重要，无论如何都要执行完毕再退出程序）
void function_1()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "========Hello=======" << i << std::endl;
    }
}

int main()
{
    std::thread t1(function_1);//t1线程开始运行

    try //【捕获异常的范围】
    {
        cv::Mat img = cv::imread("1.jpg");//读取一张不存在的图片，使下句的图片显示出现异常
        cv::imshow("===", img);//此处将出现异常！?错误?
        //出现异常会导致整个程序直接退出
        //捕获异常后，可以进行补救，如使t1子线程执行完毕。
    }
    catch (...)//捕获所有异常
    {
        std::cout << "catch..............." << std::endl;
        t1.join();//使子线程执行完毕
        throw;
    }

    t1.join();

    std::cout << "主程序正常退出" << std::endl;
    return 0;
}