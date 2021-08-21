　　class Counter {
　　    int value; //计数器的值 
　　    int alarm; //报警值
　　public:
　　    Counter(int a) {value = 0; alarm = a;}
　　    Counter & operator++();  //前缀的++重载
　　    Counter operator++(int); //后缀的++重载
　　    void print() {cout << value << endl; }
　　};
