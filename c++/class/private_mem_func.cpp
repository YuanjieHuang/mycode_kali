#include <iostream>
#include <cstdio>
using namespace std;

class base
{
public:
    virtual void b() = 0;
};

class derived : virtual public base
{
//    virtual void b() = 0;
};
class derived2 : public derived
{
private:
    void b() override
    {
        cout<<"derived\n";
    }
};

int main()
{
    derived2 d;
    base *ba = &d;
    ba->b();
    return 0;
}