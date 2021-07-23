#include <iostream>
using namespace std;

class Base{
public:
virtual ~Base(){}
virtual void f(){ cout << "f in Base" << endl; }int value;
};
class Derived : public Base{
public:
virtual void f(){cout << "f in Derived" << endl;}
};
int no_polymorphism() {
    Base b;
    b.f();
    //这个调用很明朗
    b.~Base();
    new (&b) Derived;
    b.f();
    //这里应该调用哪个 f()呢？？？
    return 0;
}

int polymorphism() {
    Base *b = new Base();
    b->f();
    b->~Base();
    new (b) Derived;
    b->f();
    return 0;
}

int main()
{
    no_polymorphism();
    polymorphism();
    return 0;
}

// extern void* operator new(size_t size) {
// if (size == 0)
// size = 1;
// void *last_alloc;
// while (!(last_alloc = malloc(size))) {
// if (_new_handler)
// (*_new_handler)();
// elsereturn 0;
// }
// return last_alloc;
// }