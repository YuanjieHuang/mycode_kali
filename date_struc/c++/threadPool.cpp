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