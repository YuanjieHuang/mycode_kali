// 最直接的实现思想就是：从给定链表的第一个节点开始遍历，
// 每遍历至一个节点，都将其和所有的前驱节点进行比对，如果为同一个节点，则表明当前链表中有环；
// 反之，如果遍历至链表最后一个节点，仍未找到相同的节点，则证明该链表中无环。
    //自定义 bool 类型
    typedef enum bool
    {
        False=0,
        True=1
    }bool;
    // H 为链表的表头
    bool HaveRing(link * H) {
        link * Htemp = H;
        //存储所遍历节点所有前驱节点的存储地址，64位环境下地址占 8 个字节，所以这里用 long long 类型
        long long addr[20] = { 0 };
        int length = 0, i = 0;
        //逐个遍历链表中各个节点
        while (Htemp) {
            //依次将 Htemp 和 addr 数组中记录的已遍历的地址进行比对
            for (i = 0; i < length; i++) {
                //如果比对成功，则证明有环
                if (Htemp == addr[i]) {
                    return True;
                }
            }
            //比对不成功，则记录 Htemp 节点的存储地址
            addr[length] = Htemp;
            length++;
            Htemp = Htemp->next;
        }
        return False;
    }


// 该算法的实现思想需要借助一个论点，即在一个链表中，如果 2 个指针（假设为 H1 和 H2）都从表头开始遍历链表，
// 其中 H1 每次移动 2 个节点的长度（H1 = H1->next->next）,而 H2 每次移动 1 个节点的长度（H2 = H2->next），
// 如果该链表为有环链表，则 H1、H2 最终必定会相等；反之，如果该链表中无环，则 H1、H2 永远不会相遇。
        //H为链表的表头，该函数会返回一个枚举的 bool 类型数据
    bool HaveRing(link * H) {
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