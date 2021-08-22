#include <vector>
#include <mutex>
#include <thread>
#include <functional>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <iostream>

class thread_pool
{
private:
    using task = std::function<void()>;

    std::atomic_bool _is_running; //显示线程池的状态
    std::mutex _mutex;
    std::condition_variable _cond;
    size_t _thread_no;
    std::vector<std::thread> _threads;
    std::queue<task> _tasks;

public:
    thread_pool(const thread_pool &tp) = delete;
    thread_pool &operator=(const thread_pool &tp) = delete;

public:
    thread_pool(size_t no)
        : _thread_no(no),
          _is_running(false)
    {
    }

    ~thread_pool()
    {
        if (_is_running)
            stop();
    }

private:
    void work()
    {
        std::cout << "thread " << std::this_thread::get_id() << " begin to work!" << std::endl;
        while(_is_running)
        {
            task t;
            {
                std::unique_lock<std::mutex> lock(_mutex);
                if(!_tasks.empty())
                {
                    t = _tasks.front();
                    _tasks.pop();
                }
                else if(_is_running && _tasks.empty())
                {
                    _cond.wait(lock);
                }
            }

            if(t)
            {
                t();
            }
        }

        std::cout << "thread " << std::this_thread::get_id() << " going to die!" << std::endl;
    }

public:
    void start()
    {
        this->_is_running = true;
        for (size_t i = 0; i < _thread_no; i++)
        {
            _threads.emplace_back(std::thread(&thread_pool::work, this));
        }
    }

    void stop()
    {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _is_running = false;
            _cond.notify_all();
        }

        for (std::thread &thd : _threads)
        {
            if (thd.joinable())
            {
                thd.join();
            }
        }
    }

    void append_task(const task &t)
    {
        if (_is_running)
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _tasks.push(t);
            _cond.notify_one();
        }
    }
};

void func1()
{
    std::cout << "$thread working in func1 in thread " << std::this_thread::get_id() << std::endl;
}

void func2(int n)
{
    std::cout << "#thread working in func2 in thread " << std::this_thread::get_id() << ";n is " << n << std::endl;
}

void thread_pool_test()
{
    thread_pool pool(10);
    pool.start();
    for (int i = 0; i < 20; i++)
    {
        pool.append_task(std::bind(func2, i));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    pool.stop();
}
int main()
{
    thread_pool_test();
}

/*

thread thread 139964423354112 begin to work!139964406568704 begin to work!
#thread working in func2 in thread 139964406568704;n is 0

thread 139964398176000 begin to work!
thread 139964389783296 begin to work!
thread 139964414961408 begin to work!
thread 139964372997888 begin to work!
thread 139964364605184 begin to work!thread 139964381390592 begin to work!
thread 
139964255565568 begin to work!
thread 139964356212480 begin to work!
#thread working in func2 in thread 139964406568704;n is 1
#thread working in func2 in thread 139964423354112;n is 2
#thread working in func2 in thread 139964398176000;n is 3
#thread working in func2 in thread 139964389783296;n is 4
#thread working in func2 in thread 139964414961408;n is 5
#thread working in func2 in thread 139964372997888;n is 6
#thread working in func2 in thread 139964381390592;n is 7
#thread working in func2 in thread 139964364605184;n is 8
#thread working in func2 in thread 139964255565568;n is 9
#thread working in func2 in thread 139964356212480;n is 10
#thread working in func2 in thread 139964406568704;n is 11
#thread working in func2 in thread 139964423354112;n is 12
#thread working in func2 in thread 139964398176000;n is 13
#thread working in func2 in thread 139964389783296;n is 14
#thread working in func2 in thread 139964414961408;n is 15
#thread working in func2 in thread 139964372997888;n is 16
#thread working in func2 in thread 139964381390592;n is 17
#thread working in func2 in thread 139964364605184;n is 18
#thread working in func2 in thread 139964255565568;n is 19
thread 139964372997888 going to die!
thread thread 139964398176000 going to die!
thread thread thread thread 139964356212480 going to die!
139964414961408 going to die!
thread 139964381390592 going to die!
thread 139964406568704139964364605184 going to die!
thread 139964255565568 going to die!
139964389783296 going to die! going to die!

139964423354112 going to die!

*/