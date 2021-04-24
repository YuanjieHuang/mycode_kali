#include <iostream>
#include <string>
using namespace std;
/*
在C语言中，有两种方式表示字符串：
一种是用字符数组来容纳字符串，例如char str[10] = "abc"，这样的字符串是可读写的；
一种是使用字符串常量，例如char *str = "abc"，这样的字符串只能读，不能写。
*/
int str_define(){
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4 (5, 's');

    string s = "http://c.biancheng.net";
    int len = s.length();
    cout<<len<<endl;

    string path = "D:\\demo.txt";
    FILE *fp = fopen(path.c_str(), "rt");
    return 0;
}

int str_visit(){
    string s = "1234567890";
    for(int i=0,len=s.length(); i<len; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    s[5] = '5';
    cout<<s<<endl;
    return 0;
}

int str_append(){
    string s1 = "first ";
    string s2 = "second ";
    char *s3 = "third ";
    char s4[] = "fourth ";
    char ch = '@';
    string s5 = s1 + s2;
    string s6 = s1 + s3;
    string s7 = s1 + s4;
    string s8 = s1 + ch;

    cout<<s5<<endl<<s6<<endl<<s7<<endl<<s8<<endl;
    return 0;
}

int str_insert(){
    string s1, s2, s3;
    s1 = s2 = "1234567890";
    s3 = "aaa";
    s1.insert(5, s3);
    cout<< s1 <<endl;
    s2.insert(5, "bbb");
    cout<< s2 <<endl;
    return 0;
}
int str_erase(){
    string s1, s2, s3;
    s1 = s2 = s3 = "1234567890";
    s2.erase(5);
    s3.erase(5, 3);
    cout<< s1 <<endl;
    cout<< s2 <<endl;
    cout<< s3 <<endl;
    return 0;
}
int get_substr(){
    string s1 = "first second third";
    string s2;
    s2 = s1.substr(6, 6);
    cout<< s1 <<endl;
    cout<< s2 <<endl;
    return 0;
}
int str_find(){
    string s1 = "first second third";
    string s2 = "second";
    //第一个参数为待查找的子字符串，它可以是 string 字符串，也可以是C风格的字符串。第二个参数为开始查找的位置（下标）；如果不指明，则从第0个字符开始查找。
    int index = s1.find(s2,5);
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}
int str_rfind(){
    string s1 = "first second third";
    string s2 = "second";
    //rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回一个无穷大值4294967295。
    int index = s1.rfind(s2,5);
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}

int str_find_first_fo(){
    string s1 = "first second second third";
    string s2 = "asecond";
    // 查找子字符串和字符串共同具有的字符在字符串中首次出现的位置
    int index = s1.find_first_of(s2);
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}
int main()
{
    // str_define();
    str_visit();
    str_append();
    // str_insert();
    // str_erase();
    // get_substr();
    // str_find();
    // str_rfind();
    // str_find_first_fo();
    return 0;
}