#include<iostream>
#include<thread>
#include<string>

class Fctor
{
public:
    void operator()(std::string& msg)//按【引用】传递参数
    {
        std::cout << "from t1:" << msg << std::endl; 
            msg = "++++++++Hello+++++++++";//修改传入的参数（用于后面的主线程输出）
    }
};

int ref_transfer_para()
{
    std::string s = "-----------World-----------";//待传入的参数（用于子线程输出）

    // 方式1a：这种方式会自动复制一份参数传进去
    //Fctor fct;
    //std::thread t1(fct,s);//t1线程开始运行

    // 方式1b：这种方式会自动复制一份参数传进去
    //std::thread t1((Fctor()), s);//t1线程开始运行

    // 方式2a：按引用传递
    Fctor fct;
    std::thread t1(fct, std::ref(s));//t1线程开始运行

    // 方式2b：按引用传递
    //std::thread t1((Fctor()), std::ref(s));

    t1.join();
    std::cout << "from main:" << s << std::endl;

    return 0;
}


int main()
{
    std::string s = "----------------World---------------";
    std::cout << "Main_thread_ID:" << std::this_thread::get_id() << std::endl;//主线程ID


    std::thread t1((Fctor()), std::move(s));//子线程1(将字符串从主线程移动到子线程)
    std::cout << "Sub_thread1_ID" << t1.get_id() << std::endl;

    //线程对象只能被移动，不能被复制。
    std::thread t2 = std::move(t1);//子线程2（接管子线程1，此时子线程1为空？！）
    std::cout << "Sub_thread2_ID" << t2.get_id() << std::endl;
    //可以看到两个子线程的ID是相同的！

    t2.join();//等待子线程2结束

    //检测硬件并发特性(此句只是用来显示计算机支持的并发线程数量)
    std::cout << std::thread::hardware_concurrency() << std::endl;

    return 0;
}