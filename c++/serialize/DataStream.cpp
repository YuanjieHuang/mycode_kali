#include "DataStream.h"
#include "CustomTypeInterface.h"

DataStream::DataStream(std::unique_ptr<DataHeader> *header) :
    m_IsFirstWrite(true)//构造函数的实现
{
    if (header == nullptr) {//header对象为空指针，重置新的对象指针
        m_Header.reset(new DataHeader);
    }
    else {
        m_Header.reset(header->release());//release()释放关联的原始指针,unique_ptr相关的函数
    }
}

 

DataStream::DataStream(const DataStream &stream)//拷贝构造
{
    operator =(stream);
}

 

DataStream &DataStream::operator =(const DataStream &stream)//=重载
{
    if (&stream == this) {//比较对象和原对象相同，没有赋值的必要了
        return *this;
    }

    m_Header.reset(new DataHeader);//重载并且初始化
    *m_Header = *stream.m_Header;//相关赋值操作
    m_DataBuffer = stream.m_DataBuffer;
    m_IsFirstWrite = stream.m_IsFirstWrite;
    return *this;
}

bool DataStream::operator ==(const DataStream &stream) const//==重载
{
    if (&stream == this) {
        return true;
    }
    if (m_Header.get() == stream.m_Header.get() &&
            m_DataBuffer == stream.m_DataBuffer) {
        return true;
    }
    return false;
}

void DataStream::clear()
{
    m_IsFirstWrite = true;
    m_DataBuffer.clear();
    m_Header->reset();
}

 

void DataStream::writeHeader()
{
    int headerLen = DataHeader::s_HeaderLen;
    writeData((char *)&(m_Header->m_TotalLen), sizeof(int));
    writeData((char *)&headerLen, sizeof(int));
    writeData((char *)&m_Header->m_Id, sizeof(int));
    m_Header->m_HeaderLen = headerLen;
}

 

void DataStream::writeData(const char *data, int len)
{
    if (len == 0) {
        return ;
    }
    //把他的type写入，
    //如果是第一写入，先把header写入, 然后再写数据，更新totalLen
   if (m_IsFirstWrite) {
        m_IsFirstWrite = false;
        writeHeader();
    }
    //然后在把数据写入
    m_DataBuffer.push(data, len);
    m_Header->m_TotalLen += len;//更新totalLen
    memcpy(m_DataBuffer.begin(), &m_Header->m_TotalLen, sizeof(int));
}

 

void DataStream::writeVal(char val)
{
    char type = (char)DataType::Char;
    writeData((char *)&(type), sizeof(char));
    writeData(&val, sizeof(char));
}

void DataStream::writeVal(const std::string &val)
{
    char type = (char)DataType::String;
    writeData((char *)&(type), sizeof(char));
    int size = val.size();
    writeVal(size);
    writeData(val.c_str(), size);
}

 

void DataStream::writeVal(CustomTypeInterface *val)
{
    val->serialize(*this, (char)DataType::CustomType);
}

 

void DataStream::readHeader(const char *data)
{
    int *p = (int *)data;
    m_Header->m_TotalLen  = *p++;
    m_Header->m_HeaderLen = *p++;
    m_Header->m_Id        = *p++;
    m_Header->m_TotalLen -= m_Header->m_HeaderLen;
    m_Header->m_HeaderLen = 0;
}

//从dataBuffer的数据取出来，然后更新totalLen.

//先读取出来类型，然后读取数据
bool DataStream::readVal(char &val)
{
    char type = 0;
    if (readData(&type) && type == (char)DataType::Char) {
        return readData(&val);
    }
   return false;
}

 

bool DataStream::readVal(std::string &val)
{
    char type = 0;
    if (readData(&type) && type == (char)DataType::String) {
        int len = 0;
        if (readVal(len) && len > 0) {
            val.assign(m_DataBuffer.begin(), len);
            m_DataBuffer.removeFromFront(len);
            m_Header->m_TotalLen -= len;
        }
       return true;
    }
    return false;
}

 

bool DataStream::readVal(CustomTypeInterface *val)
{
    return val->deserialize(*this, (char)DataType::CustomType);
}

 

int DataStream::Serialize(char *buf) const//序列化
{
    int totalLen = m_Header->m_TotalLen;
    int size = m_DataBuffer.size();
    if (size <= 0 || totalLen == 0 || size != totalLen) {
        return 0;
    }
    memcpy(buf, m_DataBuffer.begin(), totalLen);
    return totalLen;
}

 

bool DataStream::Deserialize(const char *buf, int len)//反序列化
{
    if (buf == nullptr || len <= 0) {
        return false;
    }
   readHeader(buf);
   m_DataBuffer.clear();
   m_DataBuffer.push(buf + DataHeader::s_HeaderLen, len - DataHeader::s_HeaderLen);
    return true;
}

