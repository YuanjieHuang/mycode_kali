/*栈结构
栈结构是从数据的运算来分类的。而从数据的逻辑结构来看，栈结构其实是一种线性结构。
从存储结构进一步划分，栈结构包括两类：顺序栈结构、链式栈结构
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 50

typedef struct 
{
    char name[10];
    int age;
}Data;

typedef struct stack
{
    Data data[MAXLEN + 1];
    int top;
}MyStack;

MyStack *init()
{
    MyStack *p;
    if(p = (MyStack *)malloc(sizeof(MyStack)))
    {
        p->top = 0;
        return p;
    }
    return NULL;
}

int isStackEmpty(MyStack *s)
{
    int t;
    t = (s->top == 0);
    return t;
}

int isStackFull(MyStack *s)
{
    int t;
    t = (s->top == MAXLEN);
    return t;
}

void clearStack(MyStack *s)
{
    s->top = 0;
}

void freeStack(MyStack *s)
{
    if(s)
    {
        free(s);
    }
}

int pushStack(MyStack *s, Data data)
{
    if((s->top + 1) > MAXLEN)
    {
        printf("stack overflow!");
        return 0;
    }
    s->data[++s->top] = data;
    return 1;
}

Data* popStack(MyStack *s, Data data)
{
    if(s->top ==0)
    {
        printf("stack empty!");
        exit(0);
    }
    return &(s->data[s->top--]);
}

void showStack(MyStack *stack)
{
    for(int i = 1; i <= stack->top; i++)
    {
        printf("name:%-10s age:%-5d\n", stack->data[i].name, stack->data[i].age);
    }
}
Data* peekStack(MyStack *s)
{
    if(s->top == 0)
    {
        printf("stack is empty\n");
        exit(0);
    }
   return &(s->data[s->top]);
}

void main()
{
    MyStack *stack;
    Data data, *data1, *data2;
    stack = init();
    isStackEmpty(stack);
    printf("Input name age\n");
    do
    {
        scanf("%s%d", &data.name, &data.age);
        if(strcmp(data.name, "0") == 0)
        {
            break;
        }
        else
        {
            pushStack(stack, data);
        }
    } while (1);
    showStack(stack);

    do
    {
        data2 = peekStack(stack);
        printf("\033[31mpeek\033[0mname:%-10s age:%-5d\n", data2->name, data2->age);
        data1 = popStack(stack, data);
        printf("\033[32mpop\033[0mname:%-10s age:%-5d\n", data1->name, data1->age);
    } while (stack->top);

    

}