#include <iostream>
#include <cctype>
using namespace std;
// 当程序中需要对相同大小的对象频繁申请内存时，常会采用内存池（Memory Pool）技术来提高内存申请效率。
class MemPool
{
public:
    MemPool(int nItemSize,int nMemBlockSize=2048)
    :m_nItemSize(nItemSize),
    m_nMemBlockSize(nMemBlockSize),
    m_pMemBlockHeader(NULL),
    m_pFreeNodeHeader(NULL)
    {
    }
    ~MemPool();
    void*Alloc();
    void Free();
private:
    const int m_nMemBlockSize;
    const int m_nItemSize;
    struct _FreeNode
    {
        _FreeNode* pPrev;
        int data[m_nItemSize - sizeof(_FreeNode*)];
    };
    struct _MemBlock
    {
        _MemBlock*pPrev;
        _FreeNode data[m_nMemBlockSize / m_nItemSize];
    };
    _MemBlock*m_pMemBlockHeader;
    _FreeNode*m_pFreeNodeHeader;
};