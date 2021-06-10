//文件名：8-3.cpp
//单链表的建立与访问
#include <iostream>
using namespace std;

struct  linkRec {
    int  data;    
    linkRec *next;
};

int main()
{   int x; //存放输入的值
    linkRec *head, *p, *rear;	//head为表的头指针，rear指向创建链表时的表尾结点,
						//p是创建和读链表时指向被操作结点的指针
  
    head = rear = new linkRec;	//创建空链表，头结点也是最后一个结点

    //创建链表的其他结点
    while (true) {
        cin >> x;
        if (x == 0) break;
        p = new linkRec;	//申请一个结点
        p->data = x;	//将x的值存入新结点
        rear->next = p;	//将p链到表尾
        rear = p;	//p作为新的表尾
    }

    rear->next = NULL;	//设置rear为表尾，其后没有结点了

    //读链表
    cout << "链表的内容为：\n";
    p = head->next;
    while (p != NULL) {
        cout << p->data << '\t';
        p = p->next;	//使p指向下一个结点
    }
    cout << endl;

    return 0;
}

