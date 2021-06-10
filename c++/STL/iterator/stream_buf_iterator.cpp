/*
流缓冲区迭代器和流迭代器最大的区别在于，
前者仅仅会将元素以字符的形式（包括 char、wchar_t、char16_t 及 char32_t 等）读或者写到流缓冲区中，
由于不会涉及数据类型的转换，读写数据的速度比后者要快。
*/
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istreambuf_iterator
#include <string>       // std::string
#include <algorithm>    // std::copy
#include <vector>  
using namespace std;
/*
1) 通过调用 istreambuf_iterator 模板类中的默认构造函数，可以创建一个表示结尾的输入流缓冲区迭代器。
要知道，当我们从流缓冲区中不断读取数据时，总有读取完成的那一刻，这一刻就可以用此方式构建的流缓冲区迭代器表示。
举个例子：
    std::istreambuf_iterator<char> end_in;
*/
int istreambuf_iterator_test() {
    //创建结束流缓冲区迭代器
    istreambuf_iterator<char> eos;
    //创建一个从输入缓冲区读取字符元素的迭代器
    istreambuf_iterator<char> iit(cin);
    string mystring;
    cout << "向缓冲区输入元素：\n";
    //不断从缓冲区读取数据，直到读取到 EOF 流结束符
    while (iit != eos) {
        mystring += *iit++;
    }
    cout << "string：" << mystring;
    return 0;
}
/*
1) 通过传递一个流缓冲区对象，即可创建一个输出流缓冲区迭代器，比如：
    std::ostreambuf_iterator<char> out_it (std::cout);

2) 还可以借助 rdbuf()，传递一个流缓冲区的地址，也可以成功创建输出流缓冲区迭代器：
    std::ostreambuf_iterator<char> out_it (std::cout.rdbuf());
*/
int ostreambuf_iterator_test() {
    //创建一个和输出流缓冲区相关联的迭代器
    std::ostreambuf_iterator<char> out_it(std::cout); // stdout iterator
    //向输出流缓冲区中写入字符元素
    *out_it = 'S';
    *out_it = 'T';
    *out_it = 'L';
    //和 copy() 函数连用
    std::string mystring("\nhttp://c.biancheng.net/stl/");
    //将 mystring 中的字符串全部写入到输出流缓冲区中
    std::copy(mystring.begin(), mystring.end(), out_it);
    return 0;
}

int my_copy ()   
{  
    int myints[] = {10, 20, 30, 40, 50, 60, 70};  
    vector<int> myvector;  
    vector<int>::iterator it;  
      
    myvector.resize(7);   // 为容器myvector分配空间  
      
    //copy用法一：  
    //将数组myints中的七个元素复制到myvector容器中  
    copy ( myints, myints+7, myvector.begin() );  
      
    cout << "myvector contains: ";  
    for ( it = myvector.begin();  it != myvector.end();  ++it )  
    {  
        cout << " " << *it;  
    }  
    cout << endl;  
  
    //copy用法二:  
    //将数组myints中的元素向左移动一位  
    copy(myints + 1, myints + 7, myints);  
  
    cout << "myints contains: ";  
    for ( size_t i = 0; i < 7; ++i )  
    {  
        cout << " " << myints[i];  
    }  
    cout << endl;  
  
    return 0;  
}

int iostream_iterator_copy ()   
{  
     typedef vector<int> IntVector;  
     typedef istream_iterator<int> IstreamItr;  
     typedef ostream_iterator<int> OstreamItr;  
     typedef back_insert_iterator< IntVector > BackInsItr;  
   
     IntVector myvector;  
  
     // 从标准输入设备读入整数  
     // 直到输入的是非整型数据为止 请输入整数序列，按任意非数字键并回车结束输入  
     cout << "Please input element(numbers)：" << endl;  
     copy(IstreamItr(cin), IstreamItr(), BackInsItr(myvector));  
  
     //输出容器里的所有元素，元素之间用空格隔开  
     cout << "Output : " << endl;  
     copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));   
     cout << endl;  
  
    return 0;  
}  

int main() {
    my_copy ();
    iostream_iterator_copy ();
    // istreambuf_iterator_test();
    ostreambuf_iterator_test();
    return 0;
}
