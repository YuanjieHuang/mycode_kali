#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>     //freopen
using namespace std;
 
vector<string> log;

int inner_obj() {
    std::string url;
    std::cin >> url;
    std::cout << "cout：" << url << std::endl;
    std::cerr << "cerr：" << url << std::endl;
    std::clog << "clog：" << url << std::endl;
    return 0;
}

int getline_write() {
    char url[30] = {0};
    //读取一行字符串
    cin.getline(url, 30);
    //输出上一条语句读取字符串的个数
    cout << "读取了 "<<cin.gcount()<<" 个字符" << endl;
    //输出 url 数组存储的字符串
    cout.write(url, 30);
    return 0;
}
//ostream＆put(char c);
int cout_put(){//putchar <stdio.h>
    string str = "ten.gnehcnaib.c//:ptth";
    for (int i = str.length() - 1; i >= 0; i--) {
        cout.put(str[i]);  //从最后一个字符开始输出
    }
    cout.put('\n');
    return 0;
}
//ostream＆write（const char * s，streamsize n）;
int cout_write() {
    const char * str = "http://c.biancheng.net/cplus/";
    cout.write(str, 4);
    cout.write("http://", 7).write("c.biancheng.net", 15).write("/cplus/", 7);
    return 0;
}
// ostream 类中提供有 tellp() 和 seekp() 成员方法，借助它们就可以修改位于输出流缓冲区中的数据。
// streampos tellp();
int cout_tellp() {
    //定义一个文件输出流对象
    std::ofstream outfile;
    //打开 test.txt，等待接收数据
    outfile.open("test.txt");
    const char * str = "http://c.biancheng.net/cplus/";
    //将 str 字符串中的字符逐个输出到 test.txt 文件中，每个字符都会暂时存在输出流缓冲区中
    for (int i = 0; i < strlen(str); i++) {
        outfile.put(str[i]);
        //获取当前输出流
        long pos = outfile.tellp();
        std::cout << pos << std::endl;
    }
    //关闭文件之前，刷新 outfile 输出流缓冲区，使所有字符由缓冲区流入test.txt文件
    outfile.close();
    return 0;
}

int cout_seekp() {
    //定义一个文件输出流对象
    ofstream outfile;
    //打开 test.txt，等待接收数据
    outfile.open("test.txt");
    const char * str = "http://c.biancheng.net/cplus/";
    //将 str 字符串中的字符逐个输出到 test.txt 文件中，每个字符都会暂时存在输出流缓冲区中
    for (int i = 0; i < strlen(str); i++) {
        outfile.put(str[i]);
        //获取当前输出流
       
    }
    cout << "当前位置为：" << outfile.tellp() << endl;
    //调整新进入缓冲区字符的存储位置
    outfile.seekp(23);  //等价于：
                        //outfile.seekp(23, ios::beg);
                        //outfile.seekp(-6, ios::cur);
                        //outfile.seekp(-6, ios::end);
   
    cout << "新插入位置为:" << outfile.tellp() << endl;
    const char* newstr = "python/";
    outfile.write("python/", 7);
    //关闭文件之前，刷新 outfile 输出流缓冲区，使所有字符由缓冲区流入test.txt文件
    outfile.close();
    return 0;
}


//cin cout redirect
int redirect_freopen()  
{
    string name, url;
    //将标准输入流重定向到 in.txt 文件
    freopen("in.txt", "r", stdin);
    cin >> name >> url;
    //将标准输出重定向到 out.txt文件
    freopen("out.txt", "w", stdout); 
    cout << name << "\n" << url;
    return 0;
}
// streambuf * rdbuf() const;
// streambuf * rdbuf(streambuf * sb);
int redirct_rdbuf()
{
    //打开 in.txt 文件，等待读取
    ifstream fin("in.txt");
    //打开 out.txt 文件，等待写入
    ofstream fout("out.txt");
    streambuf *oldcin;
    streambuf *oldcout;
    char a[100];
    //用 rdbuf() 重新定向，返回旧输入流缓冲区指针
    oldcin = cin.rdbuf(fin.rdbuf());
    //从input.txt文件读入
    cin >> a;
    //用 rdbuf() 重新定向，返回旧输出流缓冲区指针
    oldcout = cout.rdbuf(fout.rdbuf());
    //写入 out.txt
    cout << a << endl;
    //还原标准输入输出流
    cin.rdbuf(oldcin); // 恢复键盘输入
    cout.rdbuf(oldcout); //恢复屏幕输出
    //打开的文件，最终需要手动关闭
    fin.close();
    fout.close();
    return 0;
}

int redirect_console()
{
    string name, url;
    cin >> name >> url;
    cout << name << '\n' << url;
    return 0;
}

//cache
int cache(){

    cout << "hi!" << endl;  //输出hi和一个换行，然后刷新缓冲区
    cout << "hi!" << flush;  //输出hi，然后刷新缓冲区，不附加任何额外字符
    cout << "hi!" << ends;  //输出hi和一个空字符，然后刷新缓冲区

    cout << unitbuf;  //所有输出操作后都会立即刷新缓冲区
    //任何输出都立即刷新，无缓冲
    cout << nounitbuf;  //回到正常的缓冲方式
/*
    // tie() 函数可以用来绑定输出流，它有两个重载的版本：
    ostream* tie ( ) const;  //返回指向绑定的输出流的指针。
    ostream* tie ( ostream* os );  //将 os 指向的输出流绑定的该对象上，并返回上一个绑定的输出流指针。
*/
    cin.tie(&cout);  //仅仅是用来展示，标准库已经将 cin 和 cout 关联在一起
    //old_tie 指向当前关联到 cin 的流（如果有的话）
    ostream *old_tie = cin.tie(nullptr);  // cin 不再与其他流关联
    //将 cin 与 cerr 关联，这不是一个好主意，因为 cin 应该关联到 cout
    cin.tie(&cerr);  //读取 cin 会刷新 cerr 而不是 cout
    cin.tie(old_tie);  //重建 cin 和 cout 间的正常关联
}

int f_log()
{
    
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: "; 
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    //    outfile << data << endl;
    log.reserve(10);
    log.push_back(data);

    cout << "Enter your age: "; 
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    //    outfile << data << endl;
    log.push_back(data);
    vector<string>::iterator i;
    string temp;
    for(i = log.begin(); i != log.end(); ++i)
    {
        // outfile<< *i<<endl;
        temp += *i;
        temp += '\n';
    }
    outfile << temp;
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
    // cout.seekp(23) << "当前位置为：" << cout.tellp();
    // 关闭打开的文件
    infile.close();

    return 0;
}
#if 0
void seekg_seekp()
{
    int n;
    istream fileobject;
    // 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
    fileObject.seekg( n );
    
    // 把文件的读指针从 fileObject 当前位置向后移 n 个字节
    fileObject.seekg( n, ios::cur );
    
    // 把文件的读指针从 fileObject 末尾往回移 n 个字节
    fileObject.seekg( n, ios::end );
    
    // 定位到 fileObject 的末尾
    fileObject.seekg( 0, ios::end );
}
#endif

int cout_put()
{
    int c;
    while ((c = cin.get()) != EOF)//get() 函数不会跳过空格、制表符、回车等特殊字符，所有的字符都能被读入。
        cout.put(c);
    return 0;
}
// 要将文本文件 test.txt 中的全部内容原样显示出来
int read_file()
{
    int c;
    freopen("test.txt", "r", stdin);  //将标准输入重定向为 test.txt
    while ((c = cin.get()) != EOF)
        cout.put(c);
    return 0;
}

// getline() 是 istream 类的成员函数，它有如下两个重载版本：
// istream & getline(char* buf, int bufSize);
// istream & getline(char* buf, int bufSize, char delim);

int cin_getline_2para()
{
    char szBuf[20];
    int n = 120;
    if(!cin.getline(szBuf,6))  //如果输入流中一行字符超过5个，就会出错
        cout << "error" << endl;
    cout << szBuf << endl;
    cin >> n;
    cout << n  << endl;
    cin.clear(); //clear能够清除cin内部的错误标记，使之恢复正常
    cin >> n;
    cout << n << endl;
    return 0;
}

const int MAX_LINE_LEN = 10000;  //假设文件中一行最长 10000 个字符
int cin_getline_3para()
{
    char szBuf[MAX_LINE_LEN + 10];
    freopen("test.txt", "r", stdin);  //将标准输入重定向为 test.txt
    while (cin.getline(szBuf, MAX_LINE_LEN + 5))
        cout << szBuf << endl;
    return 0;
}

// istream & ignore(int n =1, int delim = EOF);
int cin_ignore()
{
    int n;
    cin.ignore(5, 'A');
    cin >> n;
    cout << n;
    return 0;
}

int cin_operate()
{
    int n;
    while (cin >> n)
        cout << n << endl;
    return 0;
}

int cin_dudge_end()
{
    int n;
    int maxN = 0;
    while (cin >> n){  //输入没有结束，cin 就返回 true，条件就为真
        if (maxN < n)
            maxN = n;
    }
    cout << maxN <<endl;
    return 0;
}

string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug", "Sep","Oct","Nov","Dec" };
int cin_peek()
{
    int c;
    while((c = cin.peek()) != EOF) { //取输入流中的第一个字符进行查看
         int year,month,day;
         if(c >= 'A' && c <= 'Z') { //美国日期格式
            string sMonth;
            cin >> sMonth >> day >> year;
            for(int i = 0;i < 12; ++i)  //查找月份
                   if(sMonth == Months[i]) {
                    month = i + 1;
                    break;
                }
        }
        else { //中国日期格式
            cin >> year ;
            cin.ignore() >> month ; //用ignore跳过 "2011.12.3"中的'.'
            cin.ignore() >> day;
        }
        cin.ignore();   //跳过行末 '\n'
        cout<< setfill('0') << setw(2) << month ;//设置填充字符'\0'，输出宽度2
        cout << "-" << setw(2) << day << "-" << setw(4) << year << endl;
    }
    return 0;
}

int main()
{
    cin_operate();
    return 0;
}