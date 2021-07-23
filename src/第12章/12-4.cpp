　　class People {
　　public:
　　    People( const char *s )     // 默认构造函数 
　　    { strcpy(name, s);
　　      cout << "People constructor:"  << '[' << name << ']' << endl;
　　    }; 
　　
　　    ~People()     // 析构函数
　　    { cout << "People destructor: " << '[' << name << ']' << endl; }
　　
　　protected: 
　　    char name[20]; 
　　};
　　
