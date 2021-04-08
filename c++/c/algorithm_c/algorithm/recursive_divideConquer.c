/*
每个递归函数都必须有一个非递归定义的初始值，作为递归结束的标志。
*/

//计算正整数n的划分数
int p(int n, int m)
{
    if(m ==1 || n == 1)
    {
        return 1;
    }
    if(m > n)
    {
        return p(n, n);
    }
    if(m==n)
    {
        return 1 + p(n,m-1);
    }
    return p(n,m-1) + p(n-m,m);
}

typedef int keytype;
int binSearch(keytype key[], int low, int high, keytype k)
{
   int mid;
   if(low > high)
   {
       return -1;
   }
   else
   {
       mid = (low + high) /2;
       if(mid == k)
       {
           return mid;
       }
       if(k > mid)
       {
           return binSearch(key,mid+1,high,k);
       }
       else
       {
           return binSearch(key,low,mid-1,k);
       }
   }
}
