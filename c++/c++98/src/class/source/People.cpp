#include <iostream>
#include <cstring>
using namespace std;

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

int main()
{ 
    { People p( "zhang" );  }
    cout << endl;
    Student s1( "li", 29 );
    cout << endl;
    Student s2( "wang", 30 );
    cout << endl;
    return 0;
}