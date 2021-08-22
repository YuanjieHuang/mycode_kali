#include <iostream>
// using namespace std;
void ActivateLog()
{
    std::cout<<"Log Starting…"<<std::endl;
}
void Logging()
{
    std::cout<<"Logging…"<<std::endl;
}
class Logger
{
public:
Logger()
{
    ActivateLog();
}
~Logger()
{
    std::cout<<"Log Ending…"<<std::endl;
}
};
Logger log;//全局变量
int main()
{
    std::cout<<"Main()start"<<std::endl;
    //…application code
    Logging();
    // return (int)(&(std::cout<<"Main()end"<<std::endl));
    return 0;
}