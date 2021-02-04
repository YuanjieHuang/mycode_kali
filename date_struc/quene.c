#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QUEUELEN 50

typedef struct 
{
    char name[10];
    int age;
}Data;

typedef struct stack
{
    Data data[QUEUELEN + 1];
    int head;
    int tail;
}Queue;

Queue *queueInit()
{
    Queue *queue;
    if(queue=(Queue *)malloc(sizeof(Queue)))
    {
        queue->head = 0;
        queue->tail =0;
        return queue;
    }
    else
    {
        return NULL;
    }
}

int isQueueEmpty(Queue *queue)
{
    int temp;
    temp = queue->head == queue->tail;
    return temp;
}

int isQueueFull(Queue *queue)
{
    int temp;
    temp = queue->tail == QUEUELEN;
    return temp;
}

void clearQueue(Queue *queue)
{
    queue->head = 0;
    queue->tail = 0;
}

void freeQueue(Queue *queue)
{
    if(queue != NULL)
    {
        free(queue);
    }
}

int addQueueEnd(Queue *queue, Data *data)
{
    if(queue->tail == QUEUELEN)
    {
        printf("queue is full\n");
        return 0;
    }
    else
    {
        queue->data[queue->tail++] = *data;
        return 1;
    }
}

Data *popQueueHead(Queue *queue)
{
    if(queue->tail == queue->head)
    {
        printf("queue is empty\n");
        exit(0);
    }
    else
    {
        return &(queue->data[queue->head++]);
    }
}

Data *peekQueueHead(Queue *queue)
{
    if(isQueueEmpty(queue))
    {
        return NULL;
    }
    else
    {
        return &(queue->data[queue->head]);
    }
}

int getQueueLen(Queue *queue)
{
    int temp;
    temp = queue->tail - queue->head;
    return temp;
}

void showQueue(Queue *queue)
{
    for(int i = 0; i < getQueueLen(queue); i++)
    {
        printf("name:%s age:%d\n", queue->data[i].name, queue->data[i].age);
    }
    return;
}

int main()
{
    Queue *que;
    if(NULL == (que = queueInit()))
    {
        printf("init error\n");
        return 1;
    }
    isQueueEmpty(que);
    Data *data;
    printf("Iput name age\n");
    do//enter queue
    {
        scanf("%s%d",&data->name, &data->age);
        if(strcmp(data->name, "0") == 0)
        {
            break;
        }
        else
        {
            addQueueEnd(que, data);
        }
        
    } while (1);
    showQueue(que);
    do//out queue
    {
        data = popQueueHead(que);
        printf("\033[35mout\033[0m name:%s age:%d\n", data->name, data->age);
        
    } while (data);

    clearQueue(que);
    freeQueue(que);
    
}