typedef struct Link {
    char elem; //代表数据域
    struct Link * next; //代表指针域，指向直接后继元素
}link; //link为节点名，每个节点都是一个 link 结构体

    //自定义的 bool 类型
typedef enum bool
{
    False = 0,
    True = 1
}bool;
//L1 和 L2 为 2 个单链表，函数返回 True 表示链表相交，返回 False 表示不相交
bool LinkIntersect(link * L1, link * L2) {
    link * p1 = L1;
    link * p2 = L2;
    //逐个遍历 L1 链表中的各个节点
    while (p1)
    {
        //遍历 L2 链表，针对每个 p1，依次和 p2 所指节点做比较
        while (p2) {
            //p1、p2 中记录的就是各个节点的存储地址，直接比较即可
            if (p1 == p2) {
                return True;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return False;
}

    //L1 和 L2 为 2 个单链表，函数返回 True 表示链表相交，返回 False 表示不相交
bool LinkIntersect(link * L1, link * L2) {
    link * p1 = L1;
    link * p2 = L2;
    //找到 L1 链表中的最后一个节点
    while (p1->next) {
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

    //L1 和 L2 为 2 个单链表，函数返回 True 表示链表相交，返回 False 表示不相交
bool LinkIntersect(link * L1, link * L2) {
    link * plong = L1;
    link * pshort = L2;
    link * temp = NULL;
    int num1 = 0, num2 = 0, step = 0;
    //得到 L1 的长度
    while (plong) {
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
    while (step) {
        temp = temp->next;
        step--;
    }
    //逐个比较temp和pshort链表中的节点是否相同
    while (temp && pshort) {
        if (temp == pshort) {
            return True;
        }
        temp = temp->next;
        pshort = pshort->next;
    }
    return False;
}