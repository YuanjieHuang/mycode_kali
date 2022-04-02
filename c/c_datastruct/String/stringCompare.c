#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串
int BFcompare(char * B,char *A)
{
    int i=0,j=0;
    while (i<strlen(B) && j<strlen(A)) 
    {
        if (B[i]==A[j]) 
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    //跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明子串遍历完成，在主串中成功匹配
    if (j==strlen(A)) 
    {
        return i-strlen(A)+1;
    }
    //运行到此，为i==strlen(B)的情况
    return 0;
}

//调用了普通求 next 的方式，这里并未直接对 next[1] 赋值为 1，但通过函数第一次运行，也可以得出它的值为 1
void Next(char*T,int *next)
{
    int i=1;
    next[1]=0;
    int j=0;
    while (i<strlen(T)) 
    {
        if (j==0||T[i-1]==T[j-1]) 
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int KMPcompare(char * S,char * T)
{
    int next[10];
    Next(T,next);//根据模式串T,初始化next数组
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) 
    {
        /*j==0:代表模式串的第一个字符就和当前测试的字符不相等；
        S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移*/
        if (j==0 || S[i-1]==T[j-1]) 
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j>strlen(T)) 
    {//如果条件为真，说明匹配成功
        return i-(int)strlen(T);
    }
    return -1;
}

#ifdef __cplusplus
}
#endif