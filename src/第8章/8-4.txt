//文件名：8-4.cpp
//求解约瑟夫环问题
#include <iostream>
using namespace std;

struct  node{ 
    int data;     
    node  *next;
};

int main()
{   node *head, *p, *q;  //head为链表头
    int n, i; 

    //输入n
    cout << "\ninput n:";     cin >> n;

    //建立链表
    head = p = new node; //创建第一个结点，head指向表头，p指向表尾
    p->data = 0; 
    for (i=1; i<n; ++i) {
        q = new node; //q为当前正在创建的结点
        q->data =i; 
        p->next = q;  p = q;  //将q链入表尾
    }
    p->next = head; // 头尾相连 

    // 删除过程 
    q=head; //head报数为1
    while (q->next != q) {  //只要表非空
        p = q->next;  q = p->next; //p报数为2， q报数为3
        //删除q
        p->next = q->next;  //绕过结点q
        cout << q->data << '\t';    //显示被删者的编号
        delete q;	//回收被删者的空间
        q=p->next; //让q指向报1的结点
    }

    // 打印结果 
    cout << "\n最后剩下： " <<  q->data << endl;

    return 0;
}

