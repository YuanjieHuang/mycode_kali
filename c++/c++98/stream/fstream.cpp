// ifstream::ifstream (const char* szFileName, int mode = ios::in, int);
// 第一个参数是指向文件名的指针；第二个参数是打开文件的模式标记，默认值为ios::in; 第三个参数是整型的，也有默认值，一般极少使用。
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int io_construct()
{
    ifstream inFile("in.txt", ios::in);
    if (inFile)
        inFile.close();
    else
        cout << "test.txt doesn't exist" << endl;
    ofstream oFile("test1.txt", ios::out);
    if (!oFile)
        cout << "error 1";
    else
        oFile.close();
    fstream oFile2("test2.txt", ios::out | ios::in);
    if (!oFile2)
        cout << "error 2";
    else
        oFile.close();
    return 0;
}
int read_write_txt()
{
    // int x,sum=0;
    string x;
    ifstream srcFile("in.txt", ios::in); //以文本模式打开in.txt备读
    if (!srcFile) { //打开失败
        cout << "error opening source file." << endl;
        return 0;
    }
    ofstream destFile("out.txt", ios::out); //以文本模式打开out.txt备写
    if (!destFile) {
        srcFile.close(); //程序结束前不能忘记关闭以前打开过的文件
        cout << "error opening destination file." << endl;
        return 0;
    }
    //可以像用cin那样用ifstream对象
    while (srcFile >> x) {
        // sum += x;
        //可以像 cout 那样使用 ofstream 对象
        destFile << x << " ";
    }
    // cout << "sum：" << sum << endl;
    destFile.close();
    srcFile.close();
    return 0;
}

int outFile_fail()
{
    ofstream outFile;
    outFile.close();
    if (outFile.fail()) {
        cout << "文件操作过程发生了错误！";
    }
    return 0;
}

// C++ 中使用 open() 打开的文件，在读写操作执行完毕后，应及时调用 close() 方法关闭文件，或者对文件执行写操作后及时调用 flush() 方法刷新输出流缓冲区。
int ofstream_flush()
{
    const char * url = "http://c.biancheng.net/cplus/";
    //以文本模式打开out.txt
    ofstream destFile("out.txt", ios::out);
    if (!destFile) {
        cout << "文件打开失败" << endl;
        return 0;
    }
    //向out.txt文件中写入 url 字符串
    destFile << url;
    //刷新输出流缓冲区
    destFile.flush();
    //程序抛出一个异常
    // throw "Exception";
    //关闭打开的 out.txt 文件
    destFile.close();
    return 0;
}

class CStudent
{
public:
    char szName[20];
    int age;
};
int ofstream_write()
{
    CStudent s;
    char name[20]= "zhangSan";
    memmove(s.szName,name,sizeof(name));
    s.age = 20;
    ofstream outFile("students.dat", ios::out | ios::binary);
    // while (cin >> s.szName >> s.age)
        outFile.write((char*)&s, sizeof(s));
    outFile.close();
    return 0;
}

int ifstream_read()
{
    CStudent s;       
    ifstream inFile("students.dat",ios::in|ios::binary); //二进制读方式打开
    if(!inFile) {
        cout << "error" <<endl;
        return 0;
    }
    while(inFile.read((char *)&s, sizeof(s))) { //一直读到文件结束
        cout << s.szName << " " << s.age << endl;   
    }
    inFile.close();
    return 0;
}

int f_put()
{
    char c;
    //以二进制形式打开文件
    ofstream outFile("out.txt", ios::out | ios::binary);
    if (!outFile) {
        cout << "error" << endl;
        return 0;
    }
    while (cin >> c) {
        //将字符 c 写入 out.txt 文件
        outFile.put(c);
    }
    outFile.close();
    return 0;
}

int f_get()
{
    char c;
    //以二进制形式打开文件
    ifstream inFile("out.txt", ios::out | ios::binary);
    if (!inFile) {
        cout << "error" << endl;
        return 0;
    }
    while ( (c=inFile.get())&&c!=EOF )   //或者 while(inFile.get(c))，对应第二种语法格式
    {
        cout << c ;
    }
    inFile.close();
    return 0;
}

int f_getline()
{
    char c[40];
    ifstream inFile("in.txt", ios::in | ios::binary);
    if (!inFile) {
        cout << "error" << endl;
        return 0;
    }
    //连续以行为单位，读取 in.txt 文件中的数据
    while (inFile.getline(c, 40)) {//inFile.getline(c,40,'c');一旦遇到字符 'c'，getline() 方法就会停止读取。 
        cout << c << endl;
    }
    inFile.close();
    return 0;
}
/*

    ifstream 类和 fstream 类有 seekg 成员函数，可以设置文件读指针的位置；
    ofstream 类和 fstream 类有 seekp 成员函数，可以设置文件写指针的位置。

    ifstream 类和 fstream 类还有 tellg 成员函数，能够返回文件读指针的位置；
    ofstream 类和 fstream 类还有 tellp 成员函数，能够返回文件写指针的位置。

    要获取文件长度，可以用 seekg 函数将文件读指针定位到文件尾部，再用 tellg 函数获取文件读指针的位置，此位置即为文件长度。
    例题：假设学生记录文件 students.dat 是按照姓名排好序的，编写程序，
    在 students.dat 文件中用折半查找的方法找到姓名为 Jack 的学生记录，并将其年龄改为 20（假设文件很大，无法全部读入内存）。程序如下：
*/
int seekg_bin_search()
{
    CStudent s;       
    fstream ioFile("students.dat", ios::in|ios::out);//用既读又写的方式打开
    if(!ioFile) {
        cout << "error" ;
        return 0;
    }
    ioFile.seekg(0,ios::end); //定位读指针到文件尾部，
                              //以便用以后tellg 获取文件长度
    int L = 0,R; // L是折半查找范围内第一个记录的序号
                  // R是折半查找范围内最后一个记录的序号
    R = ioFile.tellg() / sizeof(CStudent) - 1;
    //首次查找范围的最后一个记录的序号就是: 记录总数- 1
    do {
        int mid = (L + R)/2; //要用查找范围正中的记录和待查找的名字比对
        ioFile.seekg(mid *sizeof(CStudent),ios::beg); //定位到正中的记录
        ioFile.read((char *)&s, sizeof(s));
        int tmp = strcmp( s.szName,"Jack");
        if(tmp == 0) { //找到了
            s.age = 20;
            ioFile.seekp(mid*sizeof(CStudent),ios::beg);
            ioFile.write((char*)&s, sizeof(s));
            break;
        }
        else if (tmp > 0) //继续到前一半查找
            R = mid - 1 ;
        else  //继续到后一半查找
            L = mid + 1;
    }while(L <= R);
    ioFile.close();
    return 0;
}


int main()
{
    read_write_txt();
    // io_construct();
    // outFile_fail();
    // ofstream_write();
    // ofstream_flush();
    // ifstream_read();
    // f_put();
    // f_get();
    // f_getline();
    // seekg_bin_search();
    return 0;
}