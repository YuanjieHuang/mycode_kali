#include <iostream>
using namespace std;
class A;
typedef int (A::*NONSTATICDATAPTR);        //typedef

class A
{
public:
    A(int arg):nonStaticMember(arg){}
    int    nonStaticMember;
};

int main()
{
    NONSTATICDATAPTR dataPtr= &A::nonStaticMember;
    
    A a(10);
    cout<<a.*dataPtr<<endl;        //通过对象引用

    A *aPtr = new A(100);
    aPtr->nonStaticMember = 110;
    cout<<aPtr->*dataPtr<<endl;    //通过指针引用
    aPtr->*dataPtr = 119;
    cout<<aPtr->nonStaticMember<<endl;
    delete aPtr;
    return 0;
}