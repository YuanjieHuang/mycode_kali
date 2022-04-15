/*
线性表的基本运算
1.初始化
2.计算表长
3.获取节点
4.查找节点
5.插入节点
6.删除节点
顺序表结构
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define false 0
#define true 1
typedef struct 
{
    char key[10];
    char name[20];
    int age;
}Data;

typedef struct 
{
    Data listData[MAXLEN + 1];
    int listLen;
}Linear;

void linearInit(Linear *linear)
{
    linear->listLen = 0;
}

int getlinearLen(Linear *linear)
{
    return linear->listLen;
}

int insertNode(Linear *linear, int n, Data data)
{
    int len;
    if(linear->listLen == MAXLEN)
    {
        printf("error!! over MAXLEN!\n");
        return false;
    }
    if(n < 1 || (n > linear->listLen))
    {
        printf("insert data index uncorrect!\n");
        return false;
    }
    for(len = linear->listLen; len >= n; len--)
    {
        linear->listData[len+1] = linear->listData[len];
    }
    linear->listData[n] = data;
    linear->listLen++;
    return true;
}

int addNode(Linear *linear, Data data)
{
    if(linear->listLen >= MAXLEN)
    printf("The list is full!");
    linear->listData[++linear->listLen] = data;
    return true;
}

int deleteNode(Linear *linear, int n)
{
    int i;
    if(n < 1 || (n > linear->listLen))
    {
        printf("insert data index uncorrect!\n");
        return false;
    }
    for(i = linear->listLen; i > n; i--)//for(i=n;i<linear->listLen;i++)??
    {
        linear->listData[i-1] = linear->listData[i];
    }
    linear->listLen--;
    return true;
}

Data *findNodeByIndex(Linear *linear, int n)
{
    if(linear == NULL)
    {
        printf("input data is NULL\n");
        return NULL;
    }
    if(n<1 || n>linear->listLen+1)
    {
        printf("uncorrect index\n");
        return NULL;
    }
    return &(linear->listData[n]);
}

Data *findNodeByKwords(Linear *linear, char *key)
{
    int i;
    if(linear == NULL)
    {
        printf("input data is NULL\n");
        return NULL;
    }
    for(i = 1; i <= linear->listLen; i++)
    {
        if(strcmp(linear->listData[i].key, key) == 0)
        {
            return &(linear->listData[i]);
        }
    }
}

void showLinearNode(Linear *linear)
{
    int index;
    for(index=1;index<=linear->listLen;index++)
    {
        printf("Date:\nkey:%s,name:%s,age:%d\n", linear->listData[index].key, linear->listData[index].name, linear->listData[index].age);
    }
}

int main()
{
    int i;
    Linear linear;
    Data data;
    Data *pdata;
    char key[10];

    printf("list damon start practice");
    linearInit(&linear)   ;
    printf("init end\n");

    do
    {
        printf("please input node(keywords,name,age):\nwhile age=0 stop inputting.\n");
        fflush(stdin);
        scanf("%s%s%d",&data.key, &data.name, &data.age);
        if(data.age)
        {
            if(!addNode(&linear,data))
            {
                break;
            }
        }
        else
        {
            break;
        }
        
    }while(1);
    printf("show list index number\n");
    showLinearNode(&linear);
    fflush(stdin);
    printf("\nwill be picked up by index num\n");
    scanf("%d", &i);
    pdata = findNodeByIndex(&linear,i);
    if(pdata)
    {
        printf("the %dth node:(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);
    }
    fflush(stdin);
    printf("\nwill be picked up by keywords");
    scanf("%s", key); 
    pdata = findNodeByKwords(&linear,key);
    if(pdata)
    {
        printf("the %dth node:(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);
    }
    return 0;
}