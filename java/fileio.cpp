//#include <iostream>
//
//using namespace std;
//
//class Line
//{
//   public:
//      int getLength( void );
//      Line( int len );             // 简单的构造函数
//      Line( const Line &obj);      // 拷贝构造函数
//      ~Line();                     // 析构函数
//
//   private:
//      int *ptr;
//};
//
//// 成员函数定义，包括构造函数
//Line::Line(int len)
//{
//    cout << "调用构造函数" << endl;
//    // 为指针分配内存
//    ptr = new int;
//    *ptr = len;
//}
//
//Line::Line(const Line &obj)
//{
//    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
//    ptr = new int;
//    *ptr = *obj.ptr; // 拷贝值
//}
//
//Line::~Line(void)
//{
//    cout << "释放内存" << endl;
//    delete ptr;
//}
//int Line::getLength( void )
//{
//    return *ptr;
//}
//
//void display(Line obj)
//{
//   cout << "line 大小 : " << obj.getLength() <<endl;
//}
//
//// 程序的主函数
//int main( )
//{
//   Line line(10);
//
//   display(line);
//
//   return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Line
//{
//   public:
//      int getLength( void );
//      Line( int len );             // 简单的构造函数
//      Line( const Line &obj);      // 拷贝构造函数
//      ~Line();                     // 析构函数
//
//   private:
//      int *ptr;
//};
//
//// 成员函数定义，包括构造函数
//Line::Line(int len)
//{
//    cout << "调用构造函数" << endl;
//    // 为指针分配内存
//    ptr = new int;
//    *ptr = len;
//}
//
//Line::Line(const Line &obj)
//{
//    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
//    ptr = new int;
//    *ptr = *obj.ptr; // 拷贝值
//}
//
//Line::~Line(void)
//{
//    cout << "释放内存" << endl;
//    delete ptr;
//}
//int Line::getLength( void )
//{
//    return *ptr;
//}
//
//void display(Line obj)
//{
//   cout << "line 大小 : " << obj.getLength() <<endl;
//}
//
//// 程序的主函数
//int main( )
//{
//   Line line1(10);
//
//   Line line2 = line1; // 这里也调用了拷贝构造函数
//
//   display(line1);
//   display(line2);
//
//   return 0;
//}


//// 重载 + 运算符，用于把两个 Box 对象相加
//      Box operator+(const Box& b)
//      {
//         Box box;
//         box.length = this->length + b.length;
//         box.breadth = this->breadth + b.breadth;
//         box.height = this->height + b.height;
//         return box;
//      }
//
//#include <iostream>
//using namespace std;
//
//class Shape {
//   protected:
//      int width, height;
//   public:
//      Shape( int a=0, int b=0)
//      {
//         width = a;
//         height = b;
//      }
//     virtual int area()
//      {
//         cout << "Parent class area :" <<endl;
//         return 0;
//      }
//};
//class Rectangle: public Shape{
//   public:
//      Rectangle( int a=0, int b=0):Shape(a, b) { }
//      int area ()
//      {
//         cout << "Rectangle class area :" <<endl;
//         return (width * height);
//      }
//};
//class Triangle: public Shape{
//   public:
//      Triangle( int a=0, int b=0):Shape(a, b) { }
//      int area ()
//      {
//         cout << "Triangle class area :" <<endl;
//         return (width * height / 2);
//      }
//};
//// 程序的主函数
//int main( )
//{
//   Shape *shape;
//   Rectangle rec(10,7);
//   Triangle  tri(10,5);
//
//   // 存储矩形的地址
//   shape = &rec;
//   // 调用矩形的求面积函数 area
//   shape->area();
//
//   // 存储三角形的地址
//   shape = &tri;
//   // 调用三角形的求面积函数 area
//   shape->area();
//
//   return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int **p;
//    int i,j;   //p[4][8]
//    //开始分配4行8列的二维数据
//    p = new int *[4];
//    for(i=0;i<4;i++){
//        p[i]=new int [8];
//    }
//
//    for(i=0; i<4; i++){
//        for(j=0; j<8; j++){
//            p[i][j] = j*i;
//        }
//    }
//    //打印数据
//    for(i=0; i<4; i++){
//        for(j=0; j<8; j++)
//        {
//            if(j==0) cout<<endl;
//            cout<<p[i][j]<<"\t";
//        }
//    }
//    //开始释放申请的堆
//    for(i=0; i<4; i++){
//        delete [] p[i];
//    }
//    delete [] p;
//    return 0;
//}


//函数模板
//template <class type> ret-type func-name(parameter list)
//{
//   // 函数的主体
//}
//#include <iostream>
//#include <string>
//using namespace std;
//template <typename T>
//inline T const& Max (T const& a, T const& b)
//{
//    return a < b ? b:a;
//}
//int main ()
//{
//    int i = 39;
//    int j = 20;
//    cout << "Max(i, j): " << Max(i, j) << endl;
//    double f1 = 13.5;
//    double f2 = 20.7;
//    cout << "Max(f1, f2): " << Max(f1, f2) << endl;
//    string s1 = "Hello";
//    string s2 = "World";
//    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
//   return 0;
//}


//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <string>
//#include <stdexcept>
//
//using namespace std;
//
//template <class T>
//class Stack {
//  private:
//    vector<T> elems;     // 元素
//
//  public:
//    void push(T const&);  // 入栈
//    void pop();               // 出栈
//    T top() const;            // 返回栈顶元素
//    bool empty() const{       // 如果为空则返回真。
//        return elems.empty();
//    }
//};
//
//template <class T>
//void Stack<T>::push (T const& elem)
//{
//    // 追加传入元素的副本
//    elems.push_back(elem);
//}
//
////类模板（泛型）
//template <class T>
//void Stack<T>::pop ()
//{
//    if (elems.empty()) {
//        throw out_of_range("Stack<>::pop(): empty stack");
//    }
//    // 删除最后一个元素
//    elems.pop_back();
//}
//
//template <class T>
//T Stack<T>::top () const
//{
//    if (elems.empty()) {
//        throw out_of_range("Stack<>::top(): empty stack");
//    }
//    // 返回最后一个元素的副本
//    return elems.back();
//}
//
//int main()
//{
//    try {
//        Stack<int>         intStack;  // int 类型的栈
//        Stack<string> stringStack;    // string 类型的栈
//
//        // 操作 int 类型的栈
//        intStack.push(7);
//        cout << intStack.top() <<endl;
//
//        // 操作 string 类型的栈
//        stringStack.push("hello");
//        cout << stringStack.top() << std::endl;
//        stringStack.pop();
//        stringStack.pop();
//    }
//    catch (exception const& ex) {
//        cerr << "Exception: " << ex.what() <<endl;
//        return -1;
//    }
//}


//#include <iostream>
//using namespace std;
// //参数宏
//#define MIN(a,b) (a<b ? a : b)
//
//int main ()
//{
//   int i, j;
//   i = 100;
//   j = 30;
//   cout <<"较小的值为：" << MIN(i, j) << endl;
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//#define DEBUG
//
//#define MIN(a,b) (((a)<(b)) ? a : b)
//
//int main ()
//{
//   int i, j;
//   i = 100;
//   j = 30;
//#ifdef DEBUG
//   cerr <<"Trace: Inside main function" << endl;
//#endif
//
//#if 0
//   /* 这是注释部分 */
//   cout << MKSTR(HELLO C++) << endl;
//#endif
//
//   cout <<"The minimum is " << MIN(i, j) << endl;
//
//#ifdef DEBUG
//   cerr <<"Trace: Coming out of main function" << endl;
//#endif
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main ()
//{
//    cout << "Value of __LINE__ : " << __LINE__ << endl;
//    cout << "Value of __FILE__ : " << __FILE__ << endl;
//    cout << "Value of __DATE__ : " << __DATE__ << endl;
//    cout << "Value of __TIME__ : " << __TIME__ << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <csignal>
//#include <unistd.h>
//
//using namespace std;
//
//void signalHandler( int signum )
//{
//    cout << "Interrupt signal (" << signum << ") received.\n";
//
//    // 清理并关闭
//    // 终止程序
//
//   exit(signum);
//
//}
//
//int main ()
//{
//    // 注册信号 SIGINT 和信号处理程序
//    signal(SIGINT, signalHandler);
//
//    while(1){
//       cout << "Going to sleep...." << endl;
//       sleep(1);
//    }
//
//    return 0;
//}



#include <fstream>
#include <iostream>
using namespace std;

int main ()
{

   char data[100];

   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
   cin.getline(data, 100);

   // 向文件写入用户输入的数据
   outfile << data << endl;

   cout << "Enter your age: ";
   cin >> data;
   cin.ignore();

   // 再次向文件写入用户输入的数据
   outfile << data << endl;

   // 关闭打开的文件
   outfile.close();

   // 以读模式打开文件
   ifstream infile;
   infile.open("afile.dat");

   cout << "Reading from the file" << endl;
   infile >> data;

   // 在屏幕上写入数据
   cout << data << endl;

   // 再次从文件读取数据，并显示它
   infile >> data;
   cout << data << endl;

   // 关闭打开的文件
   infile.close();

   return 0;
}
