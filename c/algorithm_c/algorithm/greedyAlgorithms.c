/*
前提：局部最优解能导致全局最优解。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(int wight[], int index[], int num)
{
    int i,j,tmp;
    int *w_tmp = (int *)malloc(sizeof(int) * num);
    for(i=0; i<num;i++)
    {
        index[i]=i;
    }
    for(i=0;i<num;i++)
    {
        w_tmp[i] = wight[i];
    }
    for(i=0;i<num-1;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(w_tmp[j]>w_tmp[j+1])
            {
                tmp = w_tmp[j];
                w_tmp[j] = w_tmp[j+1];
                w_tmp[j+1] = tmp;
                tmp = index[j];
                index[j] = index[j+1];
                index[j+1] = tmp;

            }
        }
    }
}

void loading(int load[], int wight[], int maxLoad, int num)
{
    int i,s=0;
    int *index = (int *)malloc(sizeof(int)*num);//存放weight[]的下表，如果index[i]<index[j],则wight[i]<wight[j]
    bubbleSort(wight,index,num);
    memset(load,0x00,num*sizeof(int));
    for(i=0;i<num && wight[index[i]<=maxLoad];i++)
    {
        load[index[i]] = 1;
        maxLoad = maxLoad -wight[index[i]];
    }
}

int main()
{
    int maxLoad = 10, wight[5]={1,11,9,6,5},load[5]={0};
    loading(load,wight,maxLoad,5);
    for(int i=0;i<5;i++)
    {
        // printf("load[%d]=%d\t",i,load[i]);
        if(load[i] == 1)
        {
            printf("BOX:%d\t",i);
        }
    }
}