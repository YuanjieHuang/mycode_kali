//文件名：14-13.cpp
//图书馆系统的主函数
#include "book.h"
void initialize();	//系统初始化
void addBook();		//添加新书
void borrowBook();	//借书
void returnBook();	//还书
void displayBook();	//显示所有的书目信息

void initialize() {
    ofstream outfile("book");	//清空文件book
    Book::resetTotal();		//调用Book类的静态成员函数，将最大的馆藏号置为0
    outfile.close();
}

void addBook() {
    char ch[20];
    Book *bp;
    ofstream outfile("book",ofstream::app);	//以app方式打开文件

    Book::addTotal();						//最大的馆藏号加1
    cout << "请输入书名："; cin >> ch;
    bp = new Book(ch);

    outfile.write( reinterpret_cast<const char *>(bp), sizeof(*bp));
    delete bp;
    outfile.close();
}

void borrowBook()
{   int bookNo, readerNo;
    fstream iofile("book");					//以读写方式打开文件
    Book bk;

    cout << "请输入书号和读者号："; cin >> bookNo >> readerNo;

    iofile.seekg((bookNo - 1) * sizeof(book));	//按照馆藏号定位到所读记录
    iofile.read( reinterpret_cast<char *> (&bk), sizeof(Book) );
                                                //读一条记录，存入对象bk

    bk.borrow(readerNo);						//调用成员函数修改借书标记字段

    iofile.seekp((bookNo - 1) * sizeof(Book));	//按照馆藏号定位到所写记录
    iofile.write(reinterpret_cast<const char *>(&bk), sizeof(Book));	//更新记录  

    iofile.close();
}

void returnBook()
{   int bookNo;
    fstream iofile("book");
    Book bk;

    cout << "请输入书号："; cin >> bookNo ;

    iofile.seekg((bookNo - 1) * sizeof(Book));
    iofile.read(reinterpret_cast<char *> (&bk), sizeof(Book));

    bk.Return();		//复位借书标记
   
    iofile.seekp((bookNo - 1) * sizeof(Book));
    iofile.write( reinterpret_cast<const char *>(&bk), sizeof(Book));

    iofile.close();
 }

void displayBook()
{   ifstream infile("book");
    Book bk;

    infile.read(reinterpret_cast<char *> (&bk), sizeof(Book));

    while (!infile.eof()) { //顺序读文件，直到结束
        bk.display(); //显示当前书目信息的内容
        infile.read(reinterpret_cast<char *> (&bk), sizeof(Book));
    }
    infile.close();
}

int main()
{   int selector;

    while (true) {
        cout << "0 -- 退出\n";
        cout << "1 -- 初始化文件\n";
        cout << "2 -- 添加书\n";
        cout << "3 -- 借书\n";
        cout << "4 -- 还书\n";
        cout << "5 -- 显示所有书目信息\n";
        cout << "请选择（0-5）："; cin >> selector;
        if (selector == 0) break;
        switch (selector)	{
            case 1: initialize(); break;
            case 2: addBook(); break;
            case 3: borrowBook();break;
            case 4: returnBook(); break;
            case 5: displayBook();break;
        }
    }
    return 0;
}