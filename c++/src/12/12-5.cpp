　　class Student:public People {
　　public:
　　    Student(const char *s, int n): People(s)
　　    {   s_no = n;
　　        cout << "Student constructor: student number is" << s_no 
　　             << ", name is " << name << endl;
　　    }
　　    ~Student()
　　    {   cout << "Student destructor:  student numberis " << s_no 
　　             << ", name is " << name << endl;
　　    }
　　
　　private:
　　    int s_no;
　　};
　　
