int Fact(int n)
{ 
    int i, fac;
    fac = 1; //将变量fac初始化为Fact(0)的值
    for (i = 1; i <= n; ++i) fac = i * fac; //根据递推关系进行递推
    return(fac);
}
