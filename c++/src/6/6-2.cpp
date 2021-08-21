//文件名：6-2.cpp
//函数调用示例
int p( int );
int max( int a, int b );

int main()
{   int x, y;
    cin >> x >> y;
    cout << max(x, y);

    return 0?;
}

int p( int n )
{   int s =1, i;
    if (n < 0) return(0);
    for (i=1;i<=n; ++i)   s*=i;
    return(s);
} 

int max( int a, int b )
{   int n1, n2;
    n1 = p(a); n2 = p(b);
    return (n1 > n2 ? n1 : n2);
}

