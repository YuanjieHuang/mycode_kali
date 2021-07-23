#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<fstream>
class LogFile{
    std::mutex m_mutex;//锁
    std::ofstream f;public:
    LogFile()
    {
        f.open("log.txt");
    }
     void shared_print(std::string id, int value)
    {
        std::unique_lock<std::mutex> locker(m_mutex,std::defer_lock);//先不加锁
        //...此处代码不需要保护
        locker.lock();
        f << id << ":" << value << std::endl;//此处才是保护区
        std::cout << id << ":" << value << std::endl;
        locker.unlock();
        //...此处代码也不需要保护
        locker.lock();
        //以下可能又需要保护了//unique_lock可以被移动，lock_guard不可以
        std::unique_lock<std::mutex> locker2 = std::move(locker);
        //将unique_lock管理的lock交给新的unique_lock的管理
        //即将m_mutex与locker2绑定在一起！此时locker已无用
    }
};
void function_1(LogFile& log){
    for (int i = 0; i > -1000; i--)
        log.shared_print(std::string("from t1:"), i);
}
int main()//主线程{
{
    LogFile log;
    std::thread t1(function_1, std::ref(log));//t1线程开始运行for (int i = 0; i < 1000; i++)
    {
        log.shared_print(std::string("from main:"), i);
    }
    t1.join();return 0;
}