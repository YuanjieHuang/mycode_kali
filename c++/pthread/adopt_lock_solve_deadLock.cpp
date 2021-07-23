#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<fstream>

class LogFile
{
    std::mutex m_mutex;//锁1
    std::mutex m_mutex2;//锁2
    std::ofstream f;
public:
    LogFile()
    {
        f.open("log.txt");
    }
    void shared_print(std::string id, int value)
    {
        std::lock(m_mutex, m_mutex2);//lock()同时管理多个锁
        std::lock_guard<std::mutex> locker(m_mutex,std::adopt_lock);//adopt_lock即抛弃lock操作，因为上句已加锁
        std::lock_guard<std::mutex> locker2(m_mutex2, std::adopt_lock);//在析构时自动unlock()
        std::cout << id << ":" << value << std::endl;
    }
    void shared_print2(std::string id, int value)
    {
        std::lock(m_mutex, m_mutex2);
        std::lock_guard<std::mutex> locker2(m_mutex2, std::adopt_lock);
        std::lock_guard<std::mutex> locker(m_mutex, std::adopt_lock);
        std::cout << id << ":" << value << std::endl;
    }
};


void function_1(LogFile& log)
{
    for (int i = 0; i > -1000; i--)
        log.shared_print(std::string("from t1:"), i);
}

int main()//主线程
{
    LogFile log;
    std::thread t1(function_1, std::ref(log));//t1线程开始运行
    for (int i = 0; i < 1000; i++)
    {
        log.shared_print2(std::string("from main:"), i);
    }

    t1.join();

    return 0;
}