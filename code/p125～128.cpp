#ifndef STRING_CLASS
#define STRING_CLASS

#include <iostream.h>
#include <string.h>
#include <stdlib.h>

#ifndef NULL
const int NULL = 0;
#endif  //NULL

const int outOfMemory = 0, indexError = 1;

class String  {
private:
    char *str;
    int  size; //串的长度包括结束符
    void Error(int errorType, int badIndex = 0) const;
public:
    String(char *s = "");
    String(const String& s);
    
    ~String(void){ delete[]str; }

    String& operator=(const String& s); //重新赋值运算符
    ...
    int operator==(const String& s) const;
    ...

    String operator+(const String& s) const;	//字符串的拼接
    ...
    //字符串函数
    int Find(char c, int start) const;	//从star位置开始查找c
    int FindLast(char c) const;	//查找最后出现的c
    String Substr(int index, int count) const;	//求子串
    ...
    int Length(void) const;
    int IsEmpty(void) const;
    void Clear(void);
};

void String::Error(int errorType, int badIndex) const
{
    if (errorType == outOfMemory)
        cerr << "Memory exhausted!" << endl;
    else
        cerr << "Index " << badIndex << " out of range" << endl;
    exit(1);
}

String::String(char *s)
{
    size = strlen(s) + 1;	//长度包含结束符
    str = new char[size];
    if (str == NULL)	//空间申请失败
        Error(outOfMemory);
    strcpy(str,s);
}

String& String::operator= (const String& s)
{
    if (s.size != size)  {		//如果大小不同, 删除当前串并重新分配空间
        delete [] str;
        str = new char[s.size];
        if (str == NULL)
            Error(outOfMemory);
        size = s.size;
    }
    
    //复制s.str并返回引用
    strcpy(str,s.str);
    return *this;
}
//下列操作使用了C++函数
int String::operator==(const String& s) const
{
    return strcmp(str,s.str) == 0;
}

String String::operator+ (const String& s) const
{
    String temp;
    int len;
    
    delete [] temp.str;	//删除声明时生成的结束符
    
    len = size + s.size - 1;	//只保留一个结束符
    temp.str = new char[len];
    if (temp.str == NULL)   
        Error(outOfMemory);

    temp.size = len;
    strcpy(temp.str,str);	//串复制
    strcat(temp.str, s.str);	//串拼接
    return temp;                
}

int String::Find(char c, int start) const
{
    int ret;
    char *p;
    
    p = strchr(&str[start], c);
    if (p != NULL)
        ret = int(p-str);
    else
        ret = -1;
    return ret;
}

int String::FindLast(char c) const
{
    int ret;
    char *p;
    
    p = strrchr(str,c);	//用C++函数strrchr返回c最后出现的指针
    if (p != NULL)
        ret = int(p-str);	//计算位置
    else
        ret = -1;	//失败时返回-1
    return ret;
}

//返回从index开始的长度为count的子串
String String::Substr(int index, int count) const
{
    int charsLeft = size-index-1,i;	//从index到串尾的字符数
    
    String temp;		//暂存子串
    char *p, *q;
    
    if (index >= size-1)	//index过大
        return temp;
        
    if (count > charsLeft)	//count大于剩余字符数
        count = charsLeft;
        
    delete [] temp.str;	//删除声明时生成的空结束符
    
    temp.str = new char[count+1];
    if (temp.str == NULL)
        Error(outOfMemory);
        
    for(i = 0, p = temp.str, q = &str[index]; i < count; i++)	//复制count个字符
        *p++ = *q++;
    *p = 0;					//结束标志
    
    temp.size = count+1;
    return temp;
}

int String::Length(void) const
{
    return size -1;
}

void String::Clear(void)
{
    delete [] str;
    size = 1;	//含结束符的空串
    
    str = new char[size];	//给结束符分配空间
    if (str == NULL)
        Error(outOfMemory);
    str[0] = 0;
}

#endif //STRING_CLASS
