#define MAXSIZE 20
typedef int listarr[MAXSIZE];
//将数组段list[left..right]中的元素按中点优先的顺序输出
void listorder(listarr list, int left, int right)
{  
    typedef struct {
        int l;		//存放等待处理的数组段的起点下标
        int r;		//存放等待处理的数组段的终点下标
    } stacknode;		//栈中每个元素的类型
    stacknode stack[MAXSIZE];	//用于存放等待处理的数组段(即回溯点)的栈
    int top, i, j, mid;	//top为栈顶指针
    if (left <= right) {	//数组段不为空
        top = -1;	//栈的初始化
        i = left; j = right;	//i、j分别记录当前正在处理数组段的起点和终点下标
        while (i <= j || top != -1) {	//当前正在处理的数组段不为空或栈不为空
            if (i <= j) {	//当前正在处理的数组段不为空, 则遍历它
                mid = (i+j)/2;
                printf("%4d", list[mid]);	//将当前正在处理的数组段中点输出
                ++top;	//将当前正在处理的数组段中点的右部进栈
                stack[top].l = mid + 1;
                stack[top].r = j;
                j = mid - 1;	//将中点的左部作为当前即将处理的数组段
            }
            else {	//当前正在处理的数组段为空时通过栈顶元素进行回溯
                i = stack[top].l;
                j = stack[top].r;
                --top;
            }
        }
    }
}
