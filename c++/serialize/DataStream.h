// DataStream.h
#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <memory>
#include <map>
#include <list>
#include <vector>
#include <set>
#include "DataHeader.h"
#include "CharVec.h"

class CustomTypeInterface;//前向声明
class DataStream
{
public:
    DataStream(std::unique_ptr<DataHeader> *header = nullptr);
    DataStream(const DataStream &stream);

    DataStream& operator =(const DataStream &stream);
// 枚举继承char类型意思是说这个枚举里的枚举值底层是用char来存储的
    enum class DataType : char {
        UnKnown,
        Boolean,
        Char,
        WChar,
        Int,
        UInt,
        Int64,
        Double,
        String,
        WString,
        Vector,
        List,
        Map,
        Set,
        CustomType,
    };

    bool operator == (const DataStream &stream) const;
    // 指数组里存放的数据
    int totalSize() const { return m_Header->m_TotalLen; }//数据的总长
    int headerSize() const { return m_Header->m_HeaderLen; }//头部的长度
    int dataSize() const {return m_Header->m_TotalLen - m_Header->m_HeaderLen;}//内容数据的长度

    void clear();

    // write
    void writeHeader();
    void writeData(const char *data, int len);
    //这里是写入不同数据类型的数据
    DataStream& operator<<(char val);
    void writeVal(char val);
    
    DataStream& operator<<(wchar_t val);
    void writeVal(wchar_t val);
    
    DataStream& operator <<(bool val);
    void writeVal(bool val);
   
    DataStream& operator <<(int val);
    void writeVal(int val);
    
    DataStream& operator <<(unsigned int val);
    void writeVal(unsigned int val);
   
    DataStream& operator <<(int64_t val);
    void writeVal(int64_t val);
   
    DataStream& operator <<(double val);
    void writeVal(double val);
   
    DataStream& operator <<(const std::string &val);
    void writeVal(const std::string &val);
   
    DataStream& operator <<(const std::wstring &val);
    void writeVal(const std::wstring &val);
   
    DataStream& operator <<(CustomTypeInterface *val);
    void writeVal(CustomTypeInterface *val);
   //这里是往不同的STL容器中写入模板类型的数据
    template<typename T>
    DataStream& operator <<(const std::vector<T>& val);
    
    template<typename T>
    void writeVal(const std::vector<T>& val);
  
    template<typename T>
    DataStream& operator <<(const std::list<T>& val);
   
    template<typename T>
    void writeVal(const std::list<T>& val);
    
    template<typename T1, typename T2>
    DataStream& operator <<(const std::map<T1, T2>& val);

    template<typename T1, typename T2>
    void writeVal(const std::map<T1, T2>& val);

    template<typename T>
    DataStream& operator <<(const std::set<T>& val);

    template<typename T>
    void writeVal(const std::set<T>& val);

    // read
    void readHeader(const char *data);
    
    template<typename T>
    bool readData(T *val);
    
    bool operator>>(char &val);
    bool readVal(char &val);
    
    bool operator>>(wchar_t& val);
    bool readVal(wchar_t &val);
   
    bool operator>>(bool &val);
    bool readVal(bool &val);
   
    bool operator>>(int &val);
    bool readVal(int &val);

    bool operator>>(unsigned int &val);
    bool readVal(unsigned int &val);
    
    bool operator>>(int64_t &val);
    bool readVal(int64_t &val);
   
    bool operator>>(double &val);
    bool readVal(double &val);
    
    bool operator>>(std::string &val);
    bool readVal(std::string &val);
   
    bool operator>>(std::wstring &val);
    bool readVal(std::wstring &val);
    
    bool operator>>(CustomTypeInterface *val);
    bool readVal(CustomTypeInterface *val);

    template<typename T>
    bool operator>>(std::vector<T> &val);

    template<typename T>
    bool readVal(std::vector<T> &val);

    template<typename T>
    bool operator>>(std::list<T> &val);

    template<typename T>
    bool readVal(std::list<T> &val);

    template<typename T1, typename T2>
    bool operator>>(std::map<T1, T2> &val);

    template<typename T1, typename T2>
    bool readVal(std::map<T1, T2> &val);

    template<typename T>
    bool operator>>(std::set<T> &val);

    template<typename T>
    bool readVal(std::set<T> &val);

    // Serialize and Deserialize
    int Serialize(char *buf) const;
    bool Deserialize(const char *buf, int len);
private:
    std::unique_ptr<DataHeader> m_Header;//存储的客户类型指针
    CharVec  m_DataBuffer;//存储的容器
    int  m_IsFirstWrite;//判断是否为第一次写入
};

//由于这个函数是模板函数，所以我们把他放在了头文件。
template<typename T>
bool DataStream::readData(T *val)
{
    int size = m_DataBuffer.size();
    int count = sizeof(T);
    if (size < count) {
       return false;
    }
    *val = *((T*)m_DataBuffer.begin());
    m_DataBuffer.removeFromFront(count);
    m_Header->m_TotalLen -= count;
    return true;
}

