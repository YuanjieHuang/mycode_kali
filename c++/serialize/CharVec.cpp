// CharVec.cpp
#include "CharVec.h"
CharVec::CharVec() :m_Elements(nullptr), m_FirstFree(nullptr),m_Cap(nullptr)
{}//构造函数
CharVec::CharVec(const CharVec &vec)//拷贝构造
{
    auto newData = allocAndCopy(vec.begin(), vec.end());//allocAndCopy分配空间，并且初始化
    m_Elements  = newData.first;
    m_FirstFree = newData.second;
    m_Cap       = newData.second;
}
CharVec &CharVec::operator =(const CharVec &vec)//=重载
{
    auto newData = allocAndCopy(vec.begin(), vec.end());
    free();
    m_Elements  = newData.first;
    m_FirstFree = newData.second;
    m_Cap       = newData.second;
    return *this;
}
CharVec::~CharVec()//析构
{
    free();
}
 
bool CharVec::operator ==(const CharVec &vec) const//==重载
{
    if (m_Elements == vec.m_Elements &&
            m_FirstFree == vec.m_FirstFree &&
            m_Cap == vec.m_Cap) {
        return true;
    }
    return false;
}
size_t CharVec::size() const//当前元素数目
{
    return m_FirstFree - m_Elements;
}
size_t CharVec::capacity() const//容器总的空间大小
{
    return m_Cap - m_Elements;
}

char *CharVec::begin() const
{
    return m_Elements;
}
char *CharVec::end() const
{
    return m_FirstFree;
}
void CharVec::push(const char *data, int len)
{
    if (len <= 0) {
        return ;
    }
    for (int i = 0; i < len; ++i) {
        push(data[i]);
    }
}
void CharVec::push(const std::string &str)
{
    push(str.c_str(), str.size());
}
void CharVec::push(char c)
{
    checkAndAlloc();
    m_Allocator.construct(m_FirstFree++, c);
}
void CharVec::removeFromFront(int len)//从m_Element开始释放掉len长度的数据。
{
    if (len > size()) {
        return ;
    }
    char *from = m_Elements;
    char *to = m_Elements + len;
    m_Elements += len;
    for (int i = 0; i < len; ++i) {
        m_Allocator.destroy(--to);
    }
    m_Allocator.deallocate(from, m_Elements - from);
}
void CharVec::clear()//容器清空操作
{
    free();
    m_Elements = nullptr;
    m_FirstFree = nullptr;
    m_Cap = nullptr;
}
//checkAndAlloc()会先判断size是不是和capacity相等，
//然后调用reallocate进行内存的分配，重新分配的空间是原来的2倍，
//然后数据转移，使用std::move而不是拷贝可以提高效率。
void CharVec::checkAndAlloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}
void CharVec::reallocate()//类似vector的扩容操作
{
    auto newCapacity = size() ? 2 * size() : 1;//重新分配的空间是原来的2倍
    auto newData = m_Allocator.allocate(newCapacity);//allocate分配空间
    auto dest = newData;
    auto ele = m_Elements;
   for (size_t i = 0; i != size(); ++i) {
        m_Allocator.construct(dest++, std::move(*ele++));//construct初始构造
    }
    free();
    m_Elements  = newData;
    m_FirstFree = dest;
    m_Cap       = m_Elements + newCapacity;
}
void CharVec::free()
{
    if (m_Elements) {
        for (auto p = m_FirstFree; p != m_Elements;) {
            m_Allocator.destroy(--p);//destroy析构对象，此时空间还是可以使用
        }
        m_Allocator.deallocate(m_Elements, m_Cap - m_Elements);//deallocate回收空间
    }
}

std::pair<char *, char *> CharVec::allocAndCopy(char *begin, char *end)
{
   auto startPos = m_Allocator.allocate(end - begin);
   return {startPos, std::uninitialized_copy(begin, end, startPos)};
}
