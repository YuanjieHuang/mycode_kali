//求在散列表T[0..m-1]中第i次探查的散列地址hi, 0<=i<=m-1
//下面的h是散列函数, Increment是求增量序列的函数, 它依赖于解决冲突的方法
int Hash(KeyType k, int i)
{ 
    return(h(K)+Increment(i))%m; //Increment(i)相当于是di
}
