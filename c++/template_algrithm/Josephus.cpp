#include "cnode.h"

//约瑟夫问题算法
void Josephus(CNode<int> *list, int n, int m)
{
    CNode<int> *prevPtr = list, *currPtr = list->NextNode();
    
    CNode<int> *deletedNodePtr;
    
    //依次删除元素直到只剩一个元素
    for (int i=0; i < n-1; i++) {
        for (int j=0; j < m-1; j++) {
            //指针前移
            prevPtr = currPtr;
            currPtr = currPtr->NextNode();
            
            //如果是头结点, 再移一次
            if (currPtr == list) {
                prevPtr = list;
                currPtr = currPtr->NextNode();
            }
        }

        cout << "Delete person " << currPtr->data << endl;
        
        //记录被删结点, 并且指针下移
        deletedNodePtr = currPtr;
        currPtr = currPtr->NextNode();
        
        prevPtr->DeleteAfter();
        delete deletedNodePtr;
        
        //如果是头结点, 再移一次
        if (currPtr == list) {
            prevPtr = list;
            currPtr = currPtr->NextNode();
        }
    }
    
    cout << endl << "Person " << currPtr->data
         << " wins the cruise." << endl;
    
    //删除剩余结点即头结点
    deletedNodePtr = list->DeleteAfter();
    delete deletedNodePtr;
}

