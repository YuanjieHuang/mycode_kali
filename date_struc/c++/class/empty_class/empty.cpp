#include "empty.h"

int main()
{
  std::cout << "sizeof(Empty): " << sizeof(Empty) << '\n';

  Empty arr[10];
  std::cout << "sizeof(arr): " << sizeof(arr) << '\n';

  Empty a, b;
  if (&a != &b) {
    std::cout << "the size of class Empty is not zero" << '\n';
  }

  std::cout << "sizeof(Derived1): " << sizeof(Derived1) << '\n';
  std::cout << "sizeof(Derived2): " << sizeof(Derived2) << '\n';
  std::cout << "sizeof(Derived3): " << sizeof(Derived3) << '\n';
  std::cout << "sizeof(Derived4): " << sizeof(Derived4) << '\n';
  std::cout << "sizeof(Derived5): " << sizeof(Derived5) << '\n';
  std::cout << "sizeof(Derived6): " << sizeof(Derived6) << '\n';
  std::cout << "sizeof(Derived7): " << sizeof(Derived7) << '\n';

  std::cout << "sizeof(EmptyWithVirtualFunc): " << sizeof(EmptyWithVirtualFunc) << '\n';
  std::cout << "sizeof(void*): " << sizeof(void*) << '\n';
  std::cout << "sizeof(EmptyWithMenFunc): " << sizeof(EmptyWithMenFunc) << '\n';
  std::cout << "sizeof(EmptyWithStaticMem): " << sizeof(EmptyWithStaticMem) << '\n';
//   std::cout << "Derived5:"<<Derived5<<'\n';
}