#include <iostream>
#include "DataStream.h"
#include "CustomTypeInterface.h"

class InOperator
{
public:
    explicit InOperator(DataStream &stream,
                        char type,
                        const std::string &className) :
        m_InStream(stream) {
        m_InStream.writeData(&type, sizeof(char));
        m_InStream << className;
    }
 
    InOperator(const InOperator &) = delete;
    InOperator& operator=(const InOperator &) = delete;
 
    template<typename T>
    InOperator& operator *(const T &param) {
        m_InStream << param;
        return *this;
    }
 
private:
    DataStream &m_InStream;
};
 
class OutOperator
{
public:
    explicit OutOperator(DataStream &stream,
                         char type,
                         const std::string &className);
 
    OutOperator(const OutOperator &) = delete;
    OutOperator& operator=(const OutOperator &) = delete;
 
    template<typename T>
    OutOperator& operator* (T &param) {
        if (!m_IsSuccess) {
            return *this;
        }
 
        if (!(m_OutStream >> param)) {
            m_IsSuccess = false;
        }
 
        return *this;
    }
 
    bool isSuccess() const {
        return m_IsSuccess;
    }
 
private:
    DataStream  &m_OutStream;
    bool         m_IsSuccess;
};


class Test : public CustomTypeInterface
{
public:
    SerializeAndDeserialize(Test, m_A * m_B);
public:
    int  m_A;
    bool m_B;
};
int main(int argc, char *argv[])
{
    char c1 = 'c';

    Test t;
    t.m_A = 1;
    t.m_B = false;

    DataStream stream;
    stream.writeVal(c1);
    stream.writeVal(&t);
    int size = stream.totalSize();
    char *data = new char[size];
    stream.Serialize(data); 

    DataStream stream2;
    stream2.Deserialize(data, size);
    
    char c2;
    Test t2;
    stream2.readVal(c2);
    stream2.readVal(&t2);
    std::cout << c2 << t2.m_A << t2.m_B;
    return 0;

}

