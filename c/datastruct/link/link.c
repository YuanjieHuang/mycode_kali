#include "link.h"

#ifdef __cplusplus
extern "C" {
#endif

bool haveRing(link * H) 
{
    link * H1 = H->next;
    link * H2 = H;
    while (H1)
    {
        if (H1 == H2)
        {
            //链表中有环
            return True;
        }
        else
        {
            H1 = H1->next;
            if (!H1)
            {
                //链表中无环
                return False;
            }
            else
            {
                H1 = H1->next;
                H2 = H2->next;
            }
        }
    }
    //链表中无环
    return False;
}


bool isSingleLinkCross(link * L1, link * L2) 
{
    link * p1 = L1;
    link * p2 = L2;
    //逐个遍历 L1 链表中的各个节点
    while (p1)
    {
        //遍历 L2 链表，针对每个 p1，依次和 p2 所指节点做比较
        while (p2) 
        {
            //p1、p2 中记录的就是各个节点的存储地址，直接比较即可
            if (p1 == p2) 
            {
                return True;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return False;
}

bool isSingleLinkCross(link * L1, link * L2) 
{
    link * p1 = L1;
    link * p2 = L2;
    //找到 L1 链表中的最后一个节点
    while (p1->next) 
    {
        p1 = p1->next;
    }
    //找到 L2 链表中的最后一个节点
    while (p2->next)
    {
        p2 = p2->next;
    }
    //判断 L1 和 L2 链表最后一个节点是否相同
    if (p1 == p2) {
        return True;
    }
    return False;
}

bool isSingleLinkCross(link * L1, link * L2) 
{
    link * plong = L1;
    link * pshort = L2;
    link * temp = NULL;
    int num1 = 0, num2 = 0, step = 0;
    //得到 L1 的长度
    while (plong) 
    {
        num1++;
        plong = plong->next;
    }
    //得到 L2 的长度
    while (pshort)
    {
        num2++;
        pshort = pshort->next;
    }
    //重置plong和pshort，使plong代表较长的链表，pshort代表较短的链表
    plong = L1;
    pshort = L2;
    step = num1 - num2;
    if (num1 < num2) {
        plong = L2;
        pshort = L1;
        step = num2 - num1;
    }
    //在plong链表中找到和pshort等长度的子链表
    temp = plong;
    while (step) 
    {
        temp = temp->next;
        step--;
    }
    //逐个比较temp和pshort链表中的节点是否相同
    while (temp && pshort) 
    {
        if (temp == pshort) 
        {
            return True;
        }
        temp = temp->next;
        pshort = pshort->next;
    }
    return False;
}

/*==============反转单链表======================*/
    
//迭代反转法，head 为无头节点链表的头指针
link * iteration_reverse(link* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    else 
    {
        link * beg = NULL;
        link * mid = head;
        link * end = head->next;
        //一直遍历
        while (1)
        {
            //修改 mid 所指节点的指向
            mid->next = beg;
            //此时判断 end 是否为 NULL，如果成立则退出循环
            if (end == NULL) {
                break;
            }
            //整体向后移动 3 个指针
            beg = mid;
            mid = end;
            end = end->next;
        }
        //最后修改 head 头指针的指向
        head = mid;
        return head;
    }
}

//递归反转法的实现思想是从链表的尾节点开始，依次向前遍历，遍历过程依次改变各节点的指向，即另其指向前一个节点。
link* recursive_reverse(link* head) 
{
    //递归的出口
    if (head == NULL || head->next == NULL)     // 空链或只有一个结点，直接返回头指针
    {
        return head;
    }
    else
    {
        //一直递归，找到链表中最后一个节点
        link *new_head = recursive_reverse(head->next);
        //当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
        //递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。
        //每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
        head->next->next = head;
        head->next = NULL;
        //每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
        return new_head;
    }
}

link * head_reverse(link * head) 
{
    link * new_head = NULL;
    link * temp = NULL;
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    while (head != NULL)
    {
        temp = head;
        //将 temp 从 head 中摘除
        head = head->next;
        //将 temp 插入到 new_head 的头部
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
}
//就地逆置法则是直接对原链表做修改，从而实现将原链表反转。
//需要额外借助 2 个指针
link * local_reverse(link * head) 
{
    link * beg = NULL;
    link * end = NULL;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    beg = head;
    end = head->next;
    while (end != NULL) 
    {
        //将 end 从链表中摘除
        beg->next = end->next;
        //将 end 移动至链表头
        end->next = head;
        head = end;
        //调整 end 的指向，另其指向 beg 后的一个节点，为反转下一个节点做准备
        end = beg->next;
    }
    return head;
}



#ifdef __cplusplus
}
#endif