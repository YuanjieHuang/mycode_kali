#include <iostream>

using namespace std;
typedef enum A
{
    Sun,
    Mon,
    Tue

}A;
int main()
{
    
    const A a = Tue;
    cout<<a<<endl;
    A *b = const_cast<A *>(&a);
    *b = Sun;
    cout<<a<<"b:"<<*b<<endl; 

}