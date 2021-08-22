#include <iostream>

template <class T>
struct Base {
  void interface() {
    static_cast<T*>(this)->implementation();
  }
  void implementation() {
    std::cout << "Base implementation" << std::endl;
  }
  static void staticFunc() {
    // access member functions;
    T::staticSubFunc();
  }
  virtual void vir(){}
};
struct DerivedA : Base<DerivedA> {
  void implementation() {
    std::cout << "DerivedA implementation" << std::endl;
  };
  static void staticSubFunc() {
    std::cout << "staticSubFunc" << std::endl;
  };
  void vir(){std::cout<<"Derived A"<<std::endl;}
};
struct DerivedB : Base<DerivedB> {
    void vir(){std::cout<<"Derived B"<<std::endl;}
};  
int main(int argc, char **argv) {
#if 0
  DerivedA da;
  da.interface();
  da.staticFunc();  // T::staticSubFunc();
  da.vir();
  DerivedB db;
  db.interface();  // this will call the default implementation.
  db.vir();
#else
  Base<DerivedA> base* = new DerivedA;
  base->interface();
  base->staticFunc();  // T::staticSubFunc();
  base->vir();
  DerivedB db;
  base->interface();  // this will call the default implementation.
  base->vir();
#endif
  return 0;
}