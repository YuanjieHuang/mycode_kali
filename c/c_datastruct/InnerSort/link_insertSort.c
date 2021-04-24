// 表插入排序，即使用链表的存储结构对数据进行插入排序。
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
typedef struct {
    int rc;//记录项
    int next;//指针项，由于在数组中，所以只需要记录下一个结点所在数组位置的下标即可。
}SLNode;
typedef struct {
    SLNode r[SIZE];//存储记录的链表
    int length;//记录当前链表长度
}SLinkListType;
//重新排列函数
void Arrange(SLinkListType *SL){
    //令 p 指向当前要排列的记录
    int p=SL->r[0].next;
    for (int i=1; i<SL->length; i++) {
        //如果条件成立，证明原来的数据已经移动，需要通过不断找 next 域，找到其真正的位置
        while (p<i) {
            p=SL->r[p].next;
        }
        //找到之后，令 q 指针指向其链表的下一个记录所在的位置
        int q=SL->r[p].next;
        //条件成立，证明需要同下标为 i 的记录进行位置交换
        if (p!=i) {
            SLNode t;
            t=SL->r[p];
            SL->r[p]=SL->r[i];
            SL->r[i]=t;
            //交换完成后，该变 next 的值，便于后期遍历
            SL->r[i].next=p;
        }
        //最后令 p 指向下一条记录
        p=q;
    }
}
int main(int argc, const char * argv[]) {
    SLinkListType *SL=(SLinkListType*)malloc(sizeof(SLinkListType));
    SL->length=6;
    SL->r[0].rc=0;
    SL->r[0].next=4;
    
    SL->r[1].rc=49;
    SL->r[1].next=3;
    
    SL->r[2].rc=38;
    SL->r[2].next=1;
    
    SL->r[3].rc=76;
    SL->r[3].next=0;
    
    SL->r[4].rc=13;
    SL->r[4].next=5;
    
    SL->r[5].rc=27;
    SL->r[5].next=2;
    
    Arrange(SL);
    for (int i=1; i<6; i++) {
        printf("%d ",SL->r[i].rc);
    }
    return 0;
}