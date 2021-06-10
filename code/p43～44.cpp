#include "CursorList.h"

//初始化
template <class Object>
void CursorList<Object>::initializeCursorSpace()
{
    static int cursorSpaceIsInitialized = false;

    if (!cursorSpaceIsInitialized) {
        cursorSpace.resize(100);
        for (int i = 0; i < cursorSpace.size(); i++)
            cursorSpace[i].next = i + 1;
        cursorSpace[cursorSpace.size() - 1].next = 0;
        cursorSpaceIsInitialized = true;
    }
}

//分配结点
template <class Object>
int CursorList<Object>::alloc()
{
    int p = cursorSpace[0].next;
    cursorSpace[0].next = cursorSpace[p].next;
    return p;
}

//释放结点
template <class Object>
void CursorList<Object>::free(int p)
{
    cursorSpace[p].next = cursorSpace[0].next;
    cursorSpace[0].next = p;
}

//构造静态表
template <class Object>
CursorList<Object>::CursorList()
{
    initializeCursorSpace();
    header = alloc();
    cursorSpace[header].next = 0;
}

//逻辑判空
template <class Object>
bool CursorList<Object>::isEmpty() const
{
    return cursorSpace[header].next == 0;
}

//在p所指向单元后插入x
template <class Object>
void CursorList<Object>::insert(const Object & x,
                                const CursorListItr<Object> & p)
{
    if (p.current != 0) {
        int pos = p.current;
        int tmp = alloc();

        cursorSpace[tmp] = CursorNode(x, cursorSpace[pos].next);
        cursorSpace[pos].next = tmp;
    }
}

//返回值为x的第一个结点
template <class Object>
CursorListItr<Object> CursorList<Object>::find(const Object & x) const
{
    int itr = cursorSpace[header].next;
    while (itr != 0 && cursorSpace[itr].element != x)
        itr = cursorSpace[itr].next;
    return CursorListItr<Object>(itr);
}

//返回值为x的第一个结点的前驱
template <class Object>
CursorListItr<Object> CursorList<Object>
             ::findPrevious(const Object & x) const
{
    int itr = header;
    while (cursorSpace[itr].next != 0 &&
           cursorSpace[cursorSpace[itr].next].element != x)
        itr = cursorSpace[itr].next;
    return CursorListItr<Object>(itr);
}

//删除第一个值为 x的元素
template <class Object>
void CursorList<Object>::remove(const Object & x)
{
    CursorListItr<Object> p = findPrevious(x);  //查找前驱
    int pos = p.current;

    if (cursorSpace[pos].next != 0) {
        int tmp = cursorSpace[pos].next;
        cursorSpace[pos].next = cursorSpace[tmp].next;
        free (tmp);
    }
}
