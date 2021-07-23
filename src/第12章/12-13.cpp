　　class Base{
　　    int x;
　　public:
　　    Base(int xx) {x=xx; cout<<"constructing base\n";}
　　    ~Base() {cout<<"destructint base\n";}  
　　};

　　class Derive1:public Base{  
　　    int y;
　　public:
　　    Derive1(int xx, int yy): Base(xx) {y = yy; cout<<"constructing derive1\n";}
　　    ~Derive1() {cout<<"destructing derive1\n";}  
　　};

　　class Derive2:public Derive1{
　　    int z;
　　public:
　　    Derive2(int xx, int yy, int zz):Derive1(xx, yy) {z = zz;cout<<"constructing derive2\n";}
　　    ~Derive2() {cout<<"destructing derive2\n";}
　　};
　　
