#include <iostream>
#include <thread>
#include <condition_variable>
std::mutex mtx;
std::condition_variable cv;
int ready = 0;
static int point_num = 1;  
void PrintString_1()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                while(ready != 0)
                        cv.wait(lk);
                std::cout<<"1";
                ready = 1;
                cnt++;
                cv.notify_all();
        }
}

void PrintString_2()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                while(ready != 1)
                        cv.wait(lk);
                std::cout<<"2";
                ready = 2;
                cnt++;
                cv.notify_all();
        }
}

void PrintString_3()
{
        std::unique_lock<std::mutex> lk(mtx);
        int cnt = 0;
        while(cnt<10)
        {
                while(ready != 2)
                        cv.wait(lk);
                std::cout<<"1";
                for(int i=0;i<point_num;i++)
                {
                        std::cout<<".";
                }
                ready = 0;
                cnt++;
                point_num++;
                cv.notify_all();
        }
}

int main()
{
        std::thread  t1(PrintString_1);
        std::thread  t2(PrintString_2);
        std::thread  t3(PrintString_3);
        t1.join();
        t2.join();
        t3.join();
        std::cout<<std::endl;
        return 0;
}