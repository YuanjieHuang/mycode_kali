class reader{
    int no; 
    char name[10];
    char dept[20];
public:
    reader(int n, char *nm, char *d)
        {   no = n;
            strcpy(name, nm);
            strcpy(dept, d);
        }
};

class readerTeacher :public reader{
    enum {MAX = 10};//最多允许借的数量，是整个类共享的常量
    int borrowed;
    int record[MAX];
public:
    readerTeacher(int n, char *nm, char *d):reader(n, nm, d) {borrowed = 0;}
    bool bookBorrow(int bookNo);   //借书成功，返回true，否则返回false
    bool bookReturn(int bookNo);    //还书成功，返回true，否则返回false
    void show();    //显示已借书信息
};

class readerStudent :public reader {
    enum { MAX = 5};//最多允许借的数量，是整个类共享的常量
    int borrowed;
    int record[MAX];
public:
    readerStudent(int n, char *nm, char *d):reader(n, nm, d) {borrowed = 0;}
    bool bookBorrow(int bookNo);  //借书成功，返回true，否则返回false
    bool bookReturn(int bookNo);  //还书成功，返回true，否则返回false
    void show(); //显示已借书信息
};

//借书成功，返回true，否则返回false
bool readerTeacher::bookBorrow(int bookNo)	
{   if (borrowed == MAX) return false;
        else record[borrowed++] = bookNo; 
    return true;
}

//还书成功，返回true，否则返回false
bool readerTeacher::bookReturn(int bookNo)
{   int i;
    for (i=0; i < borrowed; ++i) if (record[i] == bookNo) break;
    if (i == borrowed) return false;
    while (++i < borrowed)  record[i-1] = record[i];
    --borrowed;
    return true;
}

//显示已借书信息
void readerTeacher::show()
{   for (int i = 0; i < borrowed; ++i)  cout << record[i] << '\t'; }