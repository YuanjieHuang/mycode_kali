#include <stdio.h>
#if 0
    int enQueue(int *a,int rear,int data){
        a[rear]=data;
        rear++;
        return rear;
    }
    void deQueue(int *a,int front,int rear){
        //如果 front==rear，表示队列为空
        while (front!=rear) {
            printf("出队元素：%d\n",a[front]);
            front++;
        }
    }
    int main() {
        int a[100];
        int front,rear;
        //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
        front=rear=0;
        //入队
        rear=enQueue(a, rear, 1);
        rear=enQueue(a, rear, 2);
        rear=enQueue(a, rear, 3);
        rear=enQueue(a, rear, 4);
        //出队
        deQueue(a, front, rear);
        return 0;
    }
    // 以上队列整体后移造成的影响是：
    // 顺序队列之前的数组存储空间将无法再被使用，造成了空间浪费；
    // 如果顺序表申请的空间不足够大，则直接造成程序中数组 a 溢出，产生溢出错误；

#else

    #define max 5//表示顺序表申请的空间大小
    int enQueue(int *a,int front,int rear,int data){
        //添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
        if ((rear+1)%max==front) {
            printf("空间已满");
            return rear;
        }
        a[rear%max]=data;
        rear++;
        return rear;
    }
    int  deQueue(int *a,int front,int rear){
        //如果front==rear，表示队列为空
        if(front==rear%max) {
            printf("队列为空");
            return front;
        }
        printf("%d ",a[front]);
        //front不再直接 +1，而是+1后同max进行比较，如果=max，则直接跳转到 a[0]
        front=(front+1)%max;
        return front;
    }
    int main() {
        int a[max];
        int front,rear;
        //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
        front=rear=0;
        //入队
        rear=enQueue(a,front,rear, 1);
        rear=enQueue(a,front,rear, 2);
        rear=enQueue(a,front,rear, 3);
        rear=enQueue(a,front,rear, 4);
        //出队
        front=deQueue(a, front, rear);
        //再入队
        rear=enQueue(a,front,rear, 5);
        //再出队
        front=deQueue(a, front, rear);
        //再入队
        rear=enQueue(a,front,rear, 6);
        //再出队
        front=deQueue(a, front, rear);
        front=deQueue(a, front, rear);
        front=deQueue(a, front, rear);
        front=deQueue(a, front, rear);
        return 0;
    }
#endif