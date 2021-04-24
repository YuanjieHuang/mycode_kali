    


#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table{
    int * head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length;//记录当前顺序表的长度
    int size;//记录顺序表分配的存储容量
}table;

#define Size 5 //对Size进行宏定义，表示顺序表申请空间的大小
table initTable(){
    table t;
    t.head=(int*)malloc(Size*sizeof(int));//构造一个空的顺序表，动态申请存储空间
    if (!t.head) //如果申请失败，作出提示并直接退出程序
    {
        printf("初始化失败");
        exit(0);
    }
    t.length=0;//空表的长度初始化为0
    t.size=Size;//空表的初始存储空间为Size
    return t;
}
//输出顺序表中元素的函数
void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}
int main(){
    table t=initTable();
    //向顺序表中添加元素
    for (int i=1; i<=Size; i++) {
        t.head[i-1]=i;
        t.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    return 0;
}